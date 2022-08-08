#include "lib.hpp"
#include "game/StageScene/StageScene.h"
#include "rs/util.hpp"
#include "al/util.hpp"
#include "nn/ro.h"
#include "game/System/GameSystem.h"
#include "al/factory/ProjectActorFactory.h"
#include "game/System/GameSystemFunction.hpp"
#include <functional>
#include "sead/gfx/seadTextWriter.h"
#include "al/LiveActor/LiveActorGroup.h"
#include "al/LiveActor/LiveActor.h"

HOOK_DEFINE_REPLACE(pafCtor){
	static void Callback(ProjectActorFactory * paf){
		new (paf) al::ActorFactory("アクター生成");
paf->actorTable = actorEntries;
paf->factoryCount = sizeof(actorEntries) / sizeof(actorEntries[0]);
}
};

extern "C" void _ZN19ProjectActorFactoryC2Ev(ProjectActorFactory *);

extern "C" void exl_main(void *x0, void *x1)
{
	/* Setup hooking enviroment. */
	envSetOwnProcessHandle(exl::util::proc_handle::Get());
	exl::hook::Initialize();

	/* Install the hook at the provided function pointer. Function type is checked against the callback function. */

	namespace inst = exl::armv8::inst;
	namespace reg = exl::armv8::reg;

	pafCtor::InstallAtFuncPtr(_ZN19ProjectActorFactoryC2Ev);

	exl::patch::CodePatcher(0x004c42e4).WriteInst(inst::Movz(reg::W2, 0x4d));

	/* Alternative install funcs: */
	/* InstallAtPtr takes an absolute address as a uintptr_t. */
	/* InstallAtOffset takes an offset into the main module. */

	/*
	For sysmodules/applets, you have to call the entrypoint when ready
	exl::hook::CallTargetEntrypoint(x0, x1);
	*/
}

extern "C" NORETURN void exl_exception_entry() {
    /* TODO: exception handling */
    EXL_ABORT(0x420);
}