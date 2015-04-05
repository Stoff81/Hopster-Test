//
//  CannonGame.cpp
//  ExpJam
//
//  Created by Two Tails on 09/12/2014.
//
//

#include "CannonGame.h"

#include <random>
#include "ui/CocosGUI.h"

#include "CannonGameHUD.h"
#include "CannonGameModel.h"
#include "SpriteCreator.h"

USING_NS_CC;
using namespace cocos2d::ui;

Scene* CannonGame::createScene()
{
    auto scene = Scene::createWithPhysics();
    //scene->getPhysicsWorld()->setDebugDrawMask( PhysicsWorld::DEBUGDRAW_ALL );
    
    auto gameLayer = CannonGame::create();
    gameLayer->mPhysicsWorld = scene->getPhysicsWorld();
    scene->addChild(gameLayer);
    
    auto hudLayer = CannonGameHUD::create();
    hudLayer->setModel( gameLayer->getModel() );
    scene->addChild( hudLayer );
    
    return scene;
}

bool CannonGame::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    mModel = std::make_shared<CannonGameModel>();
    
    createLand();
    createCannon();
    createCannonBall();
    createLeefy();
    
    return true;
}

void CannonGame::createLand()
///
/// Creates some sprites and adds them to the layer
///
{
    const Texture2D::TexParams repeat_params = {GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT};
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    // Add some nice sky
    Sprite* bg = createSpriteWithColor( Color4F( 0.5, 0.6, 0.9, 1 ), visibleSize.width, visibleSize.height, true );
    bg->setPosition( visibleSize.width / 2, visibleSize.height / 2 );
    bg->getTexture()->setTexParameters( repeat_params );
    this->addChild( bg, -1 );
    
    // Add some ground
    Sprite* ground = createSpriteWithColor( Color4F( 0, 0.7, 0.3, 1 ), visibleSize.width, 60, false );
    ground->setPosition( visibleSize.width / 2, 30);
    ground->getTexture()->setTexParameters( repeat_params );
    auto body = PhysicsBody::createBox( ground->getContentSize() );
    body->setDynamic( false );
    ground->setPhysicsBody(body);
    this->addChild( ground );
    
    // Add an obstacle
    Sprite* box = createSpriteWithColor( Color4F( 0, 0.7, 0.3, 1 ), 200, 300, false );
    box->setAnchorPoint( Vec2::ANCHOR_MIDDLE_BOTTOM );
    box->setPosition( 400, 60);
    box->getTexture()->setTexParameters( repeat_params );
    auto box_body = PhysicsBody::createBox( box->getContentSize() );
    box_body->setDynamic( false );
    box->setPhysicsBody(box_body);
    this->addChild( box );

}

void CannonGame::createCannon()
///
/// Creates cannon sprite and adds it to the layer
///
{
    mCannonSprite = createSpriteWithColor( Color4F( 0.6, 0.6, 0.6, 1 ), 70, 100, false );
    mCannonSprite->setAnchorPoint( Vec2::ANCHOR_MIDDLE_BOTTOM );
    mCannonSprite->setPosition( 0, 60 );
    this->addChild( mCannonSprite, 1 );
}

void CannonGame::createCannonBall()
///
/// Creates cannonBall sprite and adds it to the layer
///
{
    auto cannonBallPB = PhysicsBody::createCircle( 80, PhysicsMaterial( 0.0f, 0.8f, 0.5f ), Vec2( 0, -20 ) );
    cannonBallPB->setContactTestBitmask( 1 );
    mCannonBallSprite = Sprite::create("Bomb1.png");
    mCannonBallSprite->setPhysicsBody( cannonBallPB );
    mCannonBallSprite->setScale( 0.2, 0.2 );
    this->addChild( mCannonBallSprite );
}

void CannonGame::createLeefy()
///
/// Creates leefy target sprite and adds it to the layer
///
{
    auto leefyPB = PhysicsBody::createBox( Size(255.0f, 412.0f) );
    leefyPB->setContactTestBitmask( 1 );
    mLeefySprite = Sprite::create("Leefy-Happy.png");
    mLeefySprite->setPhysicsBody( leefyPB );
    mLeefySprite->setAnchorPoint( Vec2::ANCHOR_MIDDLE_BOTTOM );
    mLeefySprite->setScale( 0.2, 0.2 );
    randomLeefyPosition();
    this->addChild( mLeefySprite );
}

void CannonGame::randomLeefyPosition()
///
/// Moves leefy sprite to a "random" location along the ground
///
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni( visibleSize.width / 4 * 3 ,visibleSize.width - 40 ); // guaranteed unbiased
    auto random_integer = uni(rng);
    mLeefySprite->setPosition( random_integer, 100 );
}

void CannonGame::fireCannon()
///
/// Call this to fire the cannon
///
{
    mCannonBallSprite->setRotation( 0 );
    mCannonBallSprite->setPosition( 15, 85 );
    mCannonBallSprite->setVisible( true );
    Vec2 vector;
    vector.x = sin( mModel->mCannon.getAngle() * M_PI / 180 );
    vector.y = cos( mModel->mCannon.getAngle() * M_PI / 180 );
    vector *= 120 + mModel->mCannon.getPower() * 20;
    mCannonBallSprite->getPhysicsBody()->setAngularVelocity( 0 );
    mCannonBallSprite->getPhysicsBody()->setVelocity( vector );
}

void CannonGame::onEnter()
///
/// Called when the application enters this layer
///
{
    Layer::onEnter();
    
    if( _keyEventListener == NULL )
    {
        _keyEventListener = EventListenerKeyboard::create();
        _keyEventListener->onKeyPressed = CC_CALLBACK_2( CannonGame::onKeyPressed, this );
        _keyEventListener->onKeyReleased = CC_CALLBACK_2( CannonGame::onKeyReleased, this );
    }

    if( _contactEventListener == NULL )
    {
        _contactEventListener = EventListenerPhysicsContact::create();
        _contactEventListener->onContactBegin = CC_CALLBACK_1( CannonGame::onContactBegin, this );
        _contactEventListener->onContactPreSolve = CC_CALLBACK_1( CannonGame::onContactBegin, this );
    }
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority( _keyEventListener, this );
    _eventDispatcher->addEventListenerWithSceneGraphPriority( _contactEventListener, this );
    
    scheduleUpdate();
}

void CannonGame::onExit()
///
/// Called when the application exits this layer
///
{
    Layer::onExit();
    
    _eventDispatcher->removeEventListener( _keyEventListener );
    _eventDispatcher->removeEventListener( _contactEventListener );
    
    unscheduleUpdate();
}

void CannonGame::update( float delta )
///
/// Called every delta
///
/// @param delta
/// The time in seconds since the last update
///
{
    mCannonSprite->setRotation( mModel->mCannon.getAngle() );
}

bool CannonGame::onContactBegin( PhysicsContact& contact )
///
/// The callback used for any collisions that happen
///
{
    auto nodeA = contact.getShapeA()->getBody()->getNode();
    auto nodeB = contact.getShapeB()->getBody()->getNode();
    
    if (( nodeA == mLeefySprite || nodeA == mCannonBallSprite ) &&
        ( nodeB == mLeefySprite || nodeB == mCannonBallSprite ) )
    {
        mCannonBallSprite->setPosition( Vec2( -100, 0 ) ); //move off-screen
        randomLeefyPosition();
    }
    return true;
}

void CannonGame::onKeyPressed( EventKeyboard::KeyCode keyCode, Event* event )
///
/// The callback used for any key presses
///
/// @param keyCode
/// The key that has been pressed
///
/// @param Event
/// Contains additional information about the key press
///
{
    switch ( keyCode ) {
        case EventKeyboard::KeyCode::KEY_UP_ARROW:
            mModel->mCannon.setAngle( mModel->mCannon.getAngle() - 5 );
            break;
        case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
            mModel->mCannon.setAngle( mModel->mCannon.getAngle() + 5 );
            break;
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
            mModel->mCannon.setPower( mModel->mCannon.getPower() - 1 );
            break;
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
            mModel->mCannon.setPower( mModel->mCannon.getPower() + 1 );
            break;
        
        case EventKeyboard::KeyCode::KEY_SPACE:
            fireCannon();
            break;
        default:
            break;
    }
    
}

