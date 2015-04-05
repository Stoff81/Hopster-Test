//
//  CannonGameView.h
//  ExpJam
//
//  Created by Tom Stoffer on 3/04/15.
//
//

#ifndef __CANNON_GAME_VIEW__
#define __CANNON_GAME_VIEW__

#include "cocos2d.h"

class CannonGameModel;

class CannonGameView : public cocos2d::CCLayer
{
public:
    CREATE_FUNC(CannonGameView);
    
    virtual bool init();
    
    void setModel( CannonGameModel* model );
    void update( float delta );
    
private:
    CannonGameModel* mModel;
    cocos2d::Sprite* mCannonBallSprite;
    
};

#endif /* defined(__ExpJam__CannonGameView__) */
