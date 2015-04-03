//
//  CannonGameModel.cpp
//  ExpJam
//
//  Created by Tom Stoffer on 3/04/15.
//
//

#include "CannonGameModel.h"

USING_NS_CC;

bool CannonGameModel::init()
{
    if( !Scene::createWithPhysics() )
    {
        return false;
    }
    
    mTarget = PhysicsBody::createCircle(10, PHYSICSBODY_MATERIAL_DEFAULT, Vec2( 80, 10 ) );
    mCannonBall = PhysicsBody::createCircle(10, PHYSICSBODY_MATERIAL_DEFAULT, Vec2( 10, 10 ) );
    
    return true;
}

void CannonGameModel::update( float delta )
{
    
}