//
//  Vec.hpp
//  dogwalker
//
//  Created by Togo Kida on 2018/04/07.
//

#pragma once
#include "ofMain.h"
#include "ofMath.h"
#include "Position.hpp"

//vector class that stores a position, angle, and magnitude

class Vec{
public:
    float a;
    float m;
    ofVec2f p;
    float conversionArc = 180/PI;
    
    void setup(float _tx,float _ty,float _angle,float _magnitude);
    void setup(ofVec2f _pos,float _angle,float _magnitude);
    void setup(Vec _v);
    Position endPoint();//returns the endpoint of the vector as type position
    Vec add(Vec _v);//returns a vector addition
    Vec add(float _angle,float _magnitude);//returns a vector addition
    Vec sub(Vec _v);//returns a vector subration (unimplemented)
    void setStart(ofVec2f _np);//sets a new starting point for the vector
    void setEnd(ofVec2f _np);//sets a new ending point for the vector
    void setEnd(float _px,float _py);//sets a new ending point for the vector
    Position displace(ofVec2f _p, float _angle, float _magnitude);//displaces a position by an angle and a magnitude, then returns it
    float getHeading(ofVec2f _p1, ofVec2f p2);//gets the absolute heading between one position and another relative to the first
    float getHeading(Position _p1, Position p2);//gets the absolute heading between one position and another relative to the first
    float dist(ofVec2f _p1, ofVec2f _p2);
    float dist(Position _p1, Position _p2);
    float normalizeHeading(float _ang);//normalizes a heading between 0 and 180
    void drawVector(Vec _v);//draws a vector in white
    void drawVector(Vec _v,float _s);//draws a vector with a longer line for representation in white
    void drawVector(Vec _v, int r, int _g, int _b, float _s);//draws a vector with a longer line for representation in rgb
    void drawVector(Vec _v, ofColor _c, float _s);//draws a vector with a longer line for representation in ofColor
    void drawVector(Vec _v, int _r, int _g, int _b);//draws a vector with a longer line for representation in rgb
    void drawVector(Vec _v, ofColor _c);//draws a vector with a longer line for representation in ofColor
};
