//
//  CannonGame.h
//  ExpJam
//
//  Created by Two Tails on 09/12/2014.
//
//

#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "cocos2d.h"

class CannonGameModel;

class CannonGame : public cocos2d::Layer
{
    typedef cocos2d::Scene Super;
public:
    static cocos2d::Scene* createScene();
    
    CREATE_FUNC(CannonGame);

    virtual bool init();
    
    void createLand();
    void createCannon();
    void createCannonBall();
    void createLeefy();
    
    void randomLeefyPosition();
    void fireCannon();
    
    virtual void update( float delta );
    virtual void onEnter();
    virtual void onExit();
    
    bool onContactBegin( cocos2d::PhysicsContact& contact );
    
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    
    std::shared_ptr<CannonGameModel> getModel() { return mModel; };
    
private:
    
    cocos2d::EventListenerKeyboard* _keyEventListener = NULL;
    cocos2d::EventListenerPhysicsContact* _contactEventListener = NULL;

    cocos2d::Scene *mScene;
    cocos2d::PhysicsWorld *mPhysicsWorld;

    std::shared_ptr<CannonGameModel> mModel;
    
    cocos2d::Sprite* mCannonSprite;
    cocos2d::Sprite* mCannonBallSprite;
    cocos2d::Sprite* mLeefySprite;
};

#endif
