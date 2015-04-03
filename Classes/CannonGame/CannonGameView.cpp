//
//  CannonGameView.cpp
//  ExpJam
//
//  Created by Tom Stoffer on 3/04/15.
//
//

#include "CannonGameView.h"
#include "CannonGameModel.h"

USING_NS_CC;

bool CannonGameView::init()
{
    // super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    // get visible size of window
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    // Heading
    auto headingLabel = Label::createWithTTF("Welcome", "Marker Felt.ttf", 48);
    headingLabel->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 + 150));
    headingLabel->setColor(Color3B::WHITE);
    auto headingMenu = MenuItemLabel::create( headingLabel );
    this->addChild( headingMenu );

    mCannonBallSprite = Sprite::create("Bomb1.png");
    this->addChild( mCannonBallSprite );
    return true;
}

void CannonGameView::setModel( CannonGameModel* model )
{
    mModel = model;
}

void CannonGameView::update( float delta )
{
    mCannonBallSprite->setPosition( mModel->mCannonBall->getPosition() );
}