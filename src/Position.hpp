//
//  Position.hpp
//  dogwalker
//
//  Created by Togo Kida on 2018/04/09.
//

#pragma once
#include "ofMain.h"

class Position{
public:
    float x,y;
    
    void setup(float _x, float _y);
    void setup(Position _p);
    Position displace(float _angle,float _magnitude);//returns the position displaced by an angle and distance
};
