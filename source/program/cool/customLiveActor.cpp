#include "actors/customLiveActor.hpp"
#include "al/util/NerveUtil.h"
#include "al/scene/SceneObjHolder.h"

namespace ca
{
	namespace
	{
		NERVE_DEF(MyCustomActor, Wait);
		// ...
	}

	MyCustomActor::MyCustomActor(const char *name) : al::LiveActor(name) {}

	void MyCustomActor::init(al::ActorInitInfo const &info)
	{
		// init the actor

		al::initActorWithArchiveName(this, info, nullptr, "MyCustomActor");

		// set the nerve on init

		al::initNerve(this, &nrvMyCustomActorWait, 0);

		// make the actor alive

		this->makeActorAlive();
	}

	void MyCustomActor::initAfterPlacement(void)
	{
		return;
	}

	bool MyCustomActor::receiveMsg(const al::SensorMsg *message, al::HitSensor *source, al::HitSensor *target)
	{
		return false;
	}

	void MyCustomActor::attackSensor(al::HitSensor *target, al::HitSensor *source)
	{
		return;
	}

	void MyCustomActor::exeWait()
	{
		// ...
	}

	void MyCustomActor::control()
	{
		// ...
	}

} // namespace ca
