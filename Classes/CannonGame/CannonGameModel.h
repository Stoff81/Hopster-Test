//
//  CannonGameModel.h
//  ExpJam
//
//  Created by Tom Stoffer on 3/04/15.
//
//

#ifndef __CANNON_GAME_MODEL__
#define __CANNON_GAME_MODEL__

#include "cocos2d.h"

///
/// This class is used to store any data that is required in the cannon game
/// There should not be any knowledge of the view or the controller here. By making the
/// game in a model such as this. We can easily substitute out the view at a later date
/// if need be. We can also keep any game measurement in meaningful units, rather than
/// using pixels as our unit of measurement.
///
class CannonGameModel : public cocos2d::Scene
{
public:
    
    CREATE_FUNC(CannonGameModel);
    
    virtual bool init();
    void update( float delta );
    
    cocos2d::PhysicsBody* mCannonBall;
    cocos2d::PhysicsBody* mTarget;
};

#endif //__CANNON_GAME_MODEL__
