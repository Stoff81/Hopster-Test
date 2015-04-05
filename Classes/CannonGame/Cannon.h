//
//  Cannon.h
//  ExpJam
//
//  Created by Tom Stoffer on 3/04/15.
//
//

#ifndef __CANNON__
#define __CANNON__

#include "cocos2d.h"

class Cannon
{
public:
    Cannon();
    
    void setAngle( float angle );
    float getAngle(){ return mAngle; };

    void setPower( float power );
    float getPower(){ return mPower; };
    
private:
    float mAngle;
    float mPower;
};

#endif // __CANNON__
