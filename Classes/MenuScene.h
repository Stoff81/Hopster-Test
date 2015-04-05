//
//  MenuScene.h
//
//  Created by Tom Stoffer on 03/04/2014.
//
//

#ifndef __MENU_SCENE_H__
#define __MENU_SCENE_H__

#include "cocos2d.h"


class MenuScene : public cocos2d::Scene
{
    typedef cocos2d::Scene Super;
public:
    CREATE_FUNC(MenuScene);
    virtual bool init();
};

#endif
