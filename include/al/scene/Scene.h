#pragma once

#include <al/nerve/NerveExecutor.h>
#include "SceneInitInfo.h"
#include "al/LiveActor/LiveActorKit.hpp"
#include "al/audio/AudioKeeper.h"
#include "al/camera/CameraDirector.h"
#include "al/scene/SceneObjHolder.h"

namespace al
{
struct StageResourceKeeper;
struct SceneCoverCtrl;
struct SceneStopCtrl;
struct SceneMsgCtrl;

class GraphicsInitArg;

class Scene : public al::NerveExecutor,
              public al::IUseAudioKeeper,
              public al::IUseCamera,
              public al::IUseSceneObjHolder {
public:
    Scene(const char*);
    virtual al::NerveKeeper* getNerveKeeper();
    virtual ~Scene();
    // virtual void init(const al::SceneInitInfo &);
    virtual void appear();
    virtual void kill();
    virtual void movement();
    virtual void control();
    virtual void drawMain();
    virtual void drawSub();
    virtual al::AudioKeeper* getAudioKeeper();
    virtual al::SceneObjHolder* getSceneObjHolder();
    virtual al::CameraDirector* getCameraDirector();
    bool bVar1;
    sead::FixedSafeString<64> sVar1;
    StageResourceKeeper* mStageResourceKeeper;
    LiveActorKit* mLiveActorKit;
    LayoutKit* mLayoutKit;
    SceneObjHolder* mSceneObjHolder;
    SceneStopCtrl* mSceneStopCtrl;
    SceneMsgCtrl* mSceneMsgCtrl;
    SceneCoverCtrl* mSceneCoverCtrl;
    AudioDirector* mAudioDirector;
    AudioKeeper* mAudioKeeper;
    void* gap2;
};
};