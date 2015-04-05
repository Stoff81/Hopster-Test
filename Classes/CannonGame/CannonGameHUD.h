//
//  CannonGameHUD.h
//  ExpJam
//
//  Created by Tom Stoffer on 3/04/15.
//
//

#ifndef __CANNON_GAME_HUD__
#define __CANNON_GAME_HUD__

#include "cocos2d.h"

class CannonGameModel;

class CannonGameHUD : public cocos2d::Layer
{
public:
    CREATE_FUNC(CannonGameHUD);
    
    virtual bool init();
    
    void setModel( std::shared_ptr<CannonGameModel> model );
    void update( float delta );
    
private:
    std::shared_ptr<CannonGameModel> mModel;
    
    cocos2d::Sprite* mPowerBar;
};

#endif /* defined(__ExpJam__CannonGameView__) */
