//
//  SpriteCreator.h
//  ExpJam
//
//  Created by Tom Stoffer on 5/04/15.
//
//

#ifndef SPRITE_CREATOR
#define SPRITE_CREATOR

#include "cocos2d.h"

static cocos2d::Sprite* createSpriteWithColor( cocos2d::Color4F color, float width, float height, bool textured )
///
/// Convenience function that helps with creating Sprites with a blank color
///
{
    cocos2d::RenderTexture* rt = cocos2d::RenderTexture::create( 512, 512 );
    rt->beginWithClear( color.r, color.g, color.b, color.a );
    if( textured )
    {
        cocos2d::Sprite *noise = cocos2d::Sprite::create( "noise.png" );
        cocos2d::BlendFunc blend_func = { GL_SRC_COLOR, GL_ONE };
        noise->setBlendFunc( blend_func );
        noise->setPosition( 256, 256);
        noise->visit();
    }
    rt->end();
    
    return cocos2d::Sprite::createWithTexture( rt->getSprite()->getTexture(), cocos2d::Rect( 0, 0, width, height ) );
}

#endif
