#include "al/LiveActor/LiveActor.h"
#include "al/util.hpp"
#include "al/sensor/SensorMsg.h"
#include "al/util/NerveUtil.h"
#include "al/scene/ISceneObj.h"

// ca = custom actor(s)
namespace ca
{
	class MyCustomActor : public al::LiveActor
	{
	public:
		MyCustomActor(const char *name);

		// init
		virtual void init(al::ActorInitInfo const &) override;
		virtual void initAfterPlacement(void) override;

		// attack sensors

		virtual bool receiveMsg(const al::SensorMsg *message, al::HitSensor *source, al::HitSensor *target) override;
		virtual void attackSensor(al::HitSensor *source, al::HitSensor *target) override;

		// nerves

		void exeWait();
		// ...

		// control (runs every frame)
		void control() override;
	};

}
