//
//  Agent.cpp
//  dogwalker
//
//  Created by Togo Kida on 2018/04/24.
//

#include "Agent.hpp"


void Agent::setup(int _id, float _xpos, float _ypos, Position _target, int _delayer, float _maximum){
    
    ID = _id;
    x = _xpos;
    y = _ypos;
    Position fp;
    fp.setup(x, y);
    Position intP;
    intP.setup(0, 0);
    d = _delayer;
    maxV = _maximum;
    Vec v;
    v.setup(0, 0, 0, 0);
    Position t;
    t.setup(_target);
}

void Agent::setup(int _id, float _xpos, float _ypos, int _delayer, float _maximum){
    ID = _id;
    x = _xpos;
    y = _ypos;
    Position fp;
    fp.setup(x, y);
    Position intP;
    intP.setup(0, 0);//initialize
    maxV = _maximum;
    d = _delayer;
    Position t;
    t.setup(0, 0);//plug in 0 for position
}

void Agent::setup(int _id, Position _pos, Position _target, int _delayer, float _maximum){
    ID = _id;
    x = _pos.x;
    y = _pos.y;
    Position fp;
    fp.setup(_pos);
    Position intP;
    intP.setup(0, 0);//initialize
    maxV = _maximum;
    d = _delayer;
    Position t;
    t.setup(_target);
}

void Agent::setup(int _id, Position _pos, int _delayer, float _maximum) {
    ID = _id;
    x = _pos.x;
    y = _pos.y;
    Position fp;
    fp.setup(_pos);
    Position intP;
    intP.setup(0, 0);//initialize
    maxV = _maximum;
    d = _delayer;
    Position t;
    t.setup(0, 0);//plug in 0 for position
}

void Agent::draw(){

    //drawVector(v);
    //ellipse(v.p.x, v.p.y, v.m , v.m);
    //stroke(0);
    //rect(mouseX, mouseY, 100 , 100);

    calculate();
}

void Agent::calculate() {
    
    m = dist(fp, t);
    m = constrain(m, 0, maxV);
    
    a = getHeading(t, fp);
    Vec v;
    v.setup(fp.x, fp.y, a, m);
    np = v.endPoint();
    intP.x += interpolator(np.x, intP.x, del);
    intP.y += interpolator(np.y, intP.y, del);
}

void Agent::maxVSet(float _maximum){
    maxV = _maximum;
}

void Agent::aSet(float _angle){
    a = _angle;
    Vec v;
    fpV2f.set(fp.x, fp.y);
    v.setup(fpV2f, a, m);
}

void Agent::tSet(Position _pos) {
    Position t;
    t.setup(_pos);
}

int Agent::getID() {
    return ID;
}

void Agent::fpSet(Position _pos) {
    x = _pos.x;
    y = _pos.y;
    Position fp;
    fp.setup(x, y);
}

Position Agent::returnNP() {
    return intP;
}
float Agent::returnNP_x(){
    return intP.x;
}
float Agent::returnNP_y(){
    return intP.y;
}

float Agent::interpolator(float _frst, float _scnd, float _delayer) {
    float returnMe;//value that will be returned
    returnMe = (_frst - _scnd)/_delayer;
    return returnMe;
}

float Agent::getHeading(ofVec2f _p1, ofVec2f _p2){
    float angle = atan2(_p2.y - _p1.y, _p2.x - _p1.x);
    angle= -1 * angle * conversionArc;
    if(_p2.y >= _p1.y){
        angle = 360 - (angle*-1);
    }
    return angle;
}

float Agent::getHeading(Position _p1, Position _p2){
    float angle = atan2(_p2.y - _p1.y, _p2.x - _p1.x);
    angle= -1 * angle * conversionArc;
    if(_p2.y >= _p1.y){
        angle = 360 - (angle*-1);
    }
    return angle;
}

float Agent::dist(ofVec2f _p1, ofVec2f _p2){
    return ofDist(_p1.x, _p1.y, _p2.x, _p2.y);
}

float Agent::dist(Position _p1, Position _p2){
    return ofDist(_p1.x, _p1.y, _p2.x, _p2.y);
}

float Agent::constrain(float _x, float _a, float _b){
    if(_x < _a) {
        return _a;
    }
    else if(_b < _x) {
        return _b;
    }
    else
        return _x;
}


