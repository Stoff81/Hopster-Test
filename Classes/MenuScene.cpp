//
//  MenuScene.cpp
//
//  Created by Tom Stoffer on 03/04/2014.
//
//

#include "MenuScene.h"

#include "ui/CocosGUI.h"

#include "MainScene.h"

USING_NS_CC;
using namespace cocos2d::ui;

// on "init" you need to initialize your instance
bool MenuScene::init()
{
    // super init first
    if ( !Super::init() )
    {
        return false;
    }
    
    // get visible size of window
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    // Heading
    auto headingLabel = Label::createWithTTF("Choose a game:", "Marker Felt.ttf", 48);
    headingLabel->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 + 150));
    headingLabel->setColor(Color3B::WHITE);
    auto headingMenu = MenuItemLabel::create( headingLabel );
    this->addChild( headingMenu );
    
    // Cannon button
    auto button = Button::create("ButtonBlue.png", "ButtonBlue.png", "ButtonBlue.png");
    button->setTitleText("Cannons");
    button->setTitleFontSize( 48 );
    button->setTitleFontName( "Marker Felt.ttf" );
    button->setPosition( Vec2( visibleSize.width / 2, visibleSize.height / 2 ) );
    button->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:
            {
                auto scene = MainScene::create();
                TransitionScene *transition = TransitionFade::create(1, scene);
                Director::getInstance()->replaceScene(transition);
            }
                break;
            default:
                break;
        }
    });
    this->addChild(button);
    
    // done
    return true;
}