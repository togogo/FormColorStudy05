//
//  Position.cpp
//  dogwalker
//
//  Created by Togo Kida on 2018/04/09.
//

#include "Position.hpp"

void Position::setup(float _x, float _y){
    x = _x;
    y = _y;
}

void Position::setup(Position _p){
    x = _p.x;
    y = _p.y;
}

void Position::setup(ofVec2f _p){
    x = _p.x;
    y = _p.y;
}

Position Position::displace(float _angle,float _magnitude) {
    Position newP;
    newP.setup(x,y);
    newP.x+=(cos(ofDegToRad(_angle))*_magnitude);
    newP.y-=(sin(ofDegToRad(_angle))*_magnitude);
    return newP;
}
