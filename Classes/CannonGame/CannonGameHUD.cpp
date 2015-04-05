//
//  CannonGameHUD.cpp
//  ExpJam
//
//  Created by Tom Stoffer on 3/04/15.
//
//

#include "CannonGameHUD.h"
#include "CannonGameModel.h"
#include "Cannon.h"
#include "SpriteCreator.h"

USING_NS_CC;

bool CannonGameHUD::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    auto power = Label::createWithTTF( "Power:", "Marker Felt.ttf", 30 );
    power->setAnchorPoint( Vec2::ANCHOR_MIDDLE_LEFT );
    power->setPosition( 30, visibleSize.height - 30  );
    this->addChild( power, 1 );
    
    mPowerBar = createSpriteWithColor( Color4F( 0.8, 0.1, 0.1, 1 ), 20, 30, false );
    mPowerBar->setAnchorPoint( Vec2::ANCHOR_MIDDLE_LEFT );
    mPowerBar->setPosition( 120, visibleSize.height - 30 );
    this->addChild( mPowerBar, 1 );
    
    scheduleUpdate();
   
    return true;
}

void CannonGameHUD::setModel( std::shared_ptr<CannonGameModel> model )
{
    mModel = model;
}

void CannonGameHUD::update( float delta )
{
    mPowerBar->setScale( mModel->mCannon.getPower(), 1.0 );
}