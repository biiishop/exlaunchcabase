#pragma once

#include "al/LiveActor/LiveActorGroup.h"
#include "al/actor/ActorInitInfo.h"
#include "al/actor/ActorSceneInfo.h"
#include "al/hio/HioNode.h"
#include "al/layout/LayoutInitInfo.h"

namespace al {
struct ModelDrawBufferUpdater;
struct ExecuteAsyncExecutorUpdate;
struct ModelDisplayListController;
struct SwitchAreaDirector;
struct ActorResourceHolder;
struct GravityHolder;
struct GraphicsSystemInfo;
struct ModelDrawBufferCounter;
struct ClippingDirector;
struct ItemDirectorBase;
struct HitSensorDirector;
struct ScreenPointDirector;
struct ShadowDirector;
struct StageSwitchDirector;
struct DemoDirector;
struct NatureDirector;
struct ModelGroup;

struct __attribute__((aligned(8))) LiveActorKit {
    uintptr_t __vftable;
    int field_8;
    ActorResourceHolder* mActorResourceHolder;
    AreaObjDirector* mAreaObjDirector;
    ExecuteDirector* mExecuteDirector;
    GravityHolder* mGravityHolder;
    EffectSystem* mEffectSystem;
    GraphicsSystemInfo* mGraphicsSystemInfo;
    ModelDrawBufferCounter* mModelDrawBufferCounter;
    ModelDrawBufferUpdater* mModelDrawBufferUpdater;
    ExecuteAsyncExecutorUpdate* mUpdateExectorCore1;
    ExecuteAsyncExecutorUpdate* mUpdateExectorCore2;
    ModelDisplayListController* mModelDisplayListController;
    agl::DrawContext* mDrawCtx;
    LiveActorGroup* field_70;
    CameraDirector* mCameraDirector;
    ClippingDirector* mClippingDirector;
    CollisionDirector* mCollisionDirector;
    ItemDirectorBase* mItemDirectorBase;
    PlayerHolder* mPlayerHolder;
    HitSensorDirector* mHitSensorDirector;
    ScreenPointDirector* mScreenPointDirector;
    ShadowDirector* mShadowDirector;
    StageSwitchDirector* mStageSwitchDirector;
    SwitchAreaDirector* mSwitchAreaDirector;
    LiveActorGroup* field_C8;
    DemoDirector* mDemoDirector;
    GamePadSystem* mGamePadSystem;
    PadRumbleDirector* mPadRumbleDirector;
    NatureDirector* mNatureDirector;
    ModelGroup* mModelGroup;
};
};  // namespace al