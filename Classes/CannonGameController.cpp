//
//  CannonGameController.cpp
//  ExpJam
//
//  Created by Two Tails on 09/12/2014.
//
//

#include "CannonGameController.h"

#include "ui/CocosGUI.h"

#include "CannonGameView.h"
#include "CannonGameModel.h"

USING_NS_CC;
using namespace cocos2d::ui;

// on "init" you need to initialize your instance
bool CannonGameController::init()
{
    // super init first
    if ( !Super::init() )
    {
        return false;
    }
    
    mView = CannonGameView::create();
    this->addChild( mView );
    
    mModel = CannonGameModel::create();
    
    mView->setModel( mModel );
    
    // done
    return true;
}

void CannonGameController::onEnter()
{
    Super::onEnter();
    
    // create a keyboard event listener
    if( _keyEventListener == NULL )
    {
        _keyEventListener = EventListenerKeyboard::create();
        _keyEventListener->onKeyPressed = CC_CALLBACK_2( CannonGameController::onKeyPressed, this );
        _keyEventListener->onKeyReleased = CC_CALLBACK_2( CannonGameController::onKeyReleased, this );
    }
    
    // create a mouse event listener
    if( _mouseEventListener == NULL )
    {
        _mouseEventListener = EventListenerMouse::create();
        _mouseEventListener->onMouseMove = CC_CALLBACK_1( CannonGameController::onMouseMove, this );
        _mouseEventListener->onMouseUp = CC_CALLBACK_1( CannonGameController::onMouseUp, this );
        _mouseEventListener->onMouseDown = CC_CALLBACK_1( CannonGameController::onMouseDown, this );
        _mouseEventListener->onMouseScroll = CC_CALLBACK_1( CannonGameController::onMouseScroll, this );
    }
    
    // register event listeners
    //_eventDispatcher->addEventListenerWithSceneGraphPriority( _keyEventListener, this );
    //_eventDispatcher->addEventListenerWithSceneGraphPriority( _mouseEventListener, this );
    
    // schedule update calls
    scheduleUpdate();
}

void CannonGameController::onExit()
{
    Super::onExit();
    
    // de-register event listeners
    _eventDispatcher->removeEventListener( _keyEventListener );
    _eventDispatcher->removeEventListener( _mouseEventListener );
    
    // unschedule update
    unscheduleUpdate();
}

void CannonGameController::update( float delta )
{
    // called once per frame
//    cocos2d::log( "Update: %f", delta );
//    mModel->update( delta );
    mView->update( delta );
    
}


#pragma mark - Key Events


void CannonGameController::onKeyPressed( EventKeyboard::KeyCode keyCode, Event* event )
{
    cocos2d::log( "Key with keycode %d pressed", keyCode );
}

void CannonGameController::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event )
{
    cocos2d::log( "Key with keycode %d released", keyCode );
}


#pragma mark - Mouse Events


void CannonGameController::onMouseDown( Event *event )
{
    EventMouse* e = (EventMouse*)event;
    std::string str = "Mouse Down detected, Key: ";
    str += std::to_string(e->getMouseButton());
    cocos2d::log( "%s", str.c_str() );
}

void CannonGameController::onMouseUp( Event *event )
{
    EventMouse* e = (EventMouse*)event;
    std::string str = "Mouse Up detected, Key: ";
    str += std::to_string(e->getMouseButton());
    cocos2d::log( "%s", str.c_str() );
}

void CannonGameController::onMouseMove( Event *event )
{
    EventMouse* e = (EventMouse*)event;
    std::string str = "MousePosition X:";
    str += std::to_string(e->getCursorX()) + " Y:" + std::to_string(e->getCursorY());
//    cocos2d::log( "%s", str.c_str() );
}

void CannonGameController::onMouseScroll( Event *event )
{
    EventMouse* e = (EventMouse*)event;
    std::string str = "Mouse Scroll detected, X: ";
    str += std::to_string(e->getScrollX()) + " Y: " + std::to_string(e->getScrollY());
    cocos2d::log( "%s", str.c_str() );
}
