//
//  Cannon.cpp
//  ExpJam
//
//  Created by Tom Stoffer on 3/04/15.
//
//

#include "Cannon.h"

Cannon::Cannon()
{
    mAngle = 45;
    mPower = 5;
}

void Cannon::setAngle( float angle )
{
    if( angle >= 10 && angle <= 60 )
    {
        mAngle = angle;
    }
}

void Cannon::setPower( float power )
{
    if( power > 0 && power <= 10 )
    {
        mPower = power;
    }
}