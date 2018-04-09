//
//  Vec.cpp
//  dogwalker
//
//  Created by Togo Kida on 2018/04/07.
//

#include "Vec.hpp"

void Vec::setup(float _tx, float _ty, float _angle, float _magnitude){
    p.set(_tx, _ty);
    a = _angle;
    m = _magnitude;
}

void Vec::setup(ofVec2f _pos, float _angle, float _magnitude){
    p = _pos;
    a = _angle;
    m = _magnitude;
}

void Vec::setup(Vec _v){
    p = _v.p;
    a = _v.a;
    m = _v.m;
}

Position Vec::endPoint(){
    return displace(p, a, m);
}

Vec Vec::add(Vec _v){
    Position newEndPos;
    newEndPos.setup(endPoint().displace(_v.a, _v.m));
    ofVec2f newEndofVec2f;
    newEndofVec2f.set(newEndPos.x, newEndPos.y);
    float newAngle = getHeading(p, newEndofVec2f);
    Vec newVector;
    newVector.setup(p, newAngle, dist(p, newEndofVec2f));
    return newVector;
}

Vec Vec::add(float _angle, float _magnitude){
    Vec v;
    v.setup(p, _angle, _magnitude);
    Position newEndPos;
    newEndPos.setup(endPoint().displace(v.a, v.m));
    ofVec2f newEndofVec2f;
    newEndofVec2f.set(newEndPos.x, newEndPos.y);
    float newAngle = getHeading(p, newEndofVec2f);
    Vec newVector;
    newVector.setup(p, newAngle, dist(p, newEndofVec2f));
    return newVector;
}

Vec Vec::sub(Vec _v){
    return _v;
}

void Vec::setStart(ofVec2f _np){
     p = _np;
}

void Vec::setEnd(ofVec2f _np){
    a = getHeading(p,_np);
    m = dist(ofVec2f(p.x, p.y), ofVec2f(_np.x, _np.y));
}

void Vec::setEnd(float _px, float _py){
    ofVec2f np;
    np.set(_px, _py);
    a = getHeading(p, np);
    m = dist(ofVec2f(p.x, p.y), ofVec2f(np.x, np.y));
}

Position Vec::displace(ofVec2f _p,float _angle,float _magnitude){
    Position newP;
    newP.setup(_p.x, _p.y);
    //  angle=atan2(my-y,mx-x);
    //  angle=-1*angle*180/PI;
    //  if(my>y)
    //    angle=360-(angle*-1);
    newP.x += (cos(ofDegToRad(_angle))* _magnitude);
    newP.y -= (sin(ofDegToRad(_angle))* _magnitude);
    return newP;
}

float Vec::getHeading(ofVec2f _p1, ofVec2f _p2){
    float angle = atan2(_p2.y - _p1.y, _p2.x - _p1.x);
    angle= -1 * angle * conversionArc;
    if(_p2.y >= _p1.y){
        angle = 360 - (angle*-1);
    }
    return angle;
}

float Vec::dist(ofVec2f _p1, ofVec2f _p2){
    return ofDist(_p1.x, _p1.y, _p2.x, _p2.y);
}

float Vec::normalizeHeading(float _ang){
    while(_ang >= 360){
        _ang -= 360;
    }
    while(_ang <= 0){
        _ang += 360;
    }
    return _ang;
}

void Vec::drawVector(Vec _v){
    ofSetColor(255);
    ofNoFill();
    ofDrawCircle(_v.p.x, _v.p.y, 5);
    Position e=_v.endPoint();
    ofDrawLine(_v.p.x, _v.p.y, e.x, e.y);
}

void Vec::drawVector(Vec _v,float _s){
    ofSetColor(255);
    ofNoFill();
    ofDrawCircle(_v.p.x, _v.p.y, 5);
    Vec temp;
    temp.setup(_v);
    temp.m*=_s;
    Position e=temp.endPoint();
    ofDrawLine(_v.p.x, _v.p.y, e.x, e.y);
}

void Vec::drawVector(Vec _v, int _r, int _g, int _b, float _s){
    ofSetColor(_r, _g, _b);
    ofNoFill();
    ofDrawCircle(_v.p.x, _v.p.y, 5);
    Vec temp;
    temp.setup(_v);
    temp.m*=_s;
    Position e=temp.endPoint();
    ofDrawLine(_v.p.x, _v.p.y, e.x, e.y);
    
}

void Vec::drawVector(Vec _v, ofColor _c, float _s){
    ofSetColor(_c);
    ofNoFill();
    ofDrawCircle(_v.p.x, _v.p.y, 5);
    Vec temp;
    temp.setup(_v);
    temp.m*=_s;
    Position e=temp.endPoint();
    ofDrawLine(_v.p.x, _v.p.y, e.x, e.y);
}

void Vec::drawVector(Vec _v, int _r, int _g, int _b){
    ofSetColor(_r, _g, _b);
    ofNoFill();
    ofDrawCircle(_v.p.x, _v.p.y, 5);
    Position e=_v.endPoint();
    ofDrawLine(_v.p.x, _v.p.y, e.x, e.y);
}

void Vec::drawVector(Vec _v, ofColor _c){
    ofSetColor(_c);
    ofNoFill();
    ofDrawCircle(_v.p.x, _v.p.y, 5);
    Position e=_v.endPoint();
    ofDrawLine(_v.p.x, _v.p.y, e.x, e.y);
}







