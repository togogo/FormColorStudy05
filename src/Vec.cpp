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
    
    
    //Position newEnd = new Position(endPoint().displace(v.a, v.m));
    //float newAngle = getHeading(p, newEnd);
    //Vector newVector = new Vector(p, newAngle, dist(p.x, p.y, newEnd.x, newEnd.y));
    //return newVector;
}

Vec Vec::add(float _angle, float _magnitude){
    
}

Vec Vec::sub(Vec _v){
    
}

void Vec::setStart(ofVec2f _np){
    
}

void Vec::setEnd(ofVec2f _np){
    
}

void Vec::setEnd(float _px, float _py){
    
}

Position Vec::displace(ofVec2f _p,float _angle,float _magnitude){
    
}

float Vec::getHeading(ofVec2f _p1, ofVec2f p2){
    
}

float Vec::dist(ofVec2f _p1, ofVec2f _p2){
    
}

float Vec::normalizeHeading(float _ang){
    
}

void Vec::drawVector(Vec _v){
    
}

void Vec::drawVector(Vec _v,float _s){
    
}

void Vec::drawVector(Vec _v, int r, int _g, int _b, float _s){
    
}

void Vec::drawVector(Vec _v, ofColor _c, float _s){
    
}

void Vec::drawVector(Vec _v, int r, int _g, int _b){
    
}

void Vec::drawVector(Vec _v, ofColor _c){
    
}







