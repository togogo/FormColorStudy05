//
//  Agent.hpp
//  dogwalker
//
//  Created by Togo Kida on 2018/04/24.
//

#pragma once
#include "ofMain.h"
#include "Position.hpp"
//#include "Vehicle.hpp"
#include "Vec.hpp"

class Agent{
    
public:
    //fields
    float x;//x-position
    float y;//y-position
    Position fp;//xy-position, front point
    ofVec2f fpV2f;
    Position np;//xy-position, end point
    Position t;//target postion
    Position intP;//interpolator position
    float a;//angle
    float m;//magnitude
    float maxV;//max magnitude
    Vec v;//vector
    float d;//delayer value for interpolation
    int ID;//unique ID tagged to each of the Agents.
    
    void setup(int _id, float _xpos, float _ypos, Position _target, int _delayer, float _maximum);
    void setup(int _id, float _xpos, float _ypos, int _delayer, float _maximum);
    void setup(int _id, Position _pos, Position _target, int _delayer, float _maximum);
    void setup(int _id, Position _pos, int _delayer, float _maximum);
    void draw();
    void calculate();
    void maxVSet(float _maximum);
    void aSet(float _angle);
    void tSet(Position _pos);
    int getID();
    void fpSet(Position _pos);
    Position returnNP();
    float returnNP_x();
    float returnNP_y();
    //float constrain(float _x, float _a, float _b);//constrains x between a and b

};


/*
 class Agent{
 //this constitutes the grid.
 //-it can look around to see and find if ther are any
 //"hot points" around to expand or shrink.
 //-according to the "hot point," it will draw out a vector.


//fields
float x;//x-position
float y;//y-position
Position fp;//xy-position, front point
Position np;//xy-position, end point
Position t;//target postion
Position intP;//interpolator position
float a;//angle
float m;//magnitude
float maxV;//max magnitude
Vector v;//vector
float d;//delayer value for interpolation
int ID;//unique ID tagged to each of the Agents.

//Agent() { }
//if there is a target to point
Agent(int id, float xpos, float ypos, Position target, int delayer, float maximum) {
    ID = id;
    x = xpos;
    y = ypos;
    fp = new Position(x, y);
    intP = new Position(0, 0);//initialize
    d = delayer;
    maxV = maximum;
    v = new Vector(0, 0, 0, 0);//initialize
    t = new Position(target);
}
//if there is no target to point
Agent(int id, float xpos, float ypos, int delayer, float maximum ) {
    ID = id;
    x = xpos;
    y = ypos;
    fp = new Position(x, y);
    intP = new Position(0, 0);//initialize
    maxV = maximum;
    d = delayer;
    t = new Position(0, 0);//plug in 0 for position
}
//if there is target to point
Agent(int id, Position pos, Position target, int delayer, float maximum) {
    ID = id;
    x = pos.x;
    y = pos.y;
    fp = new Position(pos);
    intP = new Position(0, 0);//initialize
    maxV = maximum;
    d = delayer;
    t = new Position(target);
}
//if there is no target to point
Agent(int id, Position pos, int delayer, float maximum) {
    ID = id;
    x = pos.x;
    y = pos.y;
    fp = new Position(pos);
    intP = new Position(0, 0);//initialize
    maxV = maximum;
    d = delayer;
    t = new Position(0, 0);//plug in 0 for position
}

void draw() {
    //drawVector(v);
    //ellipse(v.p.x, v.p.y, v.m , v.m);
    //stroke(0);
    //rect(mouseX, mouseY, 100 , 100);
    calculate();
}

void calculate() {
    m = dist(fp, t);
    m = constrain(m, 0, maxV);
    a = getHeading(t, fp);
    v = new Vector(fp, a, m);
    np = v.endPoint();
    intP.x += interpolator(np.x, intP.x, del);
    intP.y += interpolator(np.y, intP.y, del);
}

void maxVSet(float maximum) {
    maxV = maximum;
}

void aSet(float angle) {
    a = angle;
    v = new Vector(fp, a, m);
}

void tSet(Position pos) {
    t = new Position(pos);
    //println("yay");
}

int getID() {
    return ID;
}

void fpSet(Position pos) {
    x = pos.x;
    y = pos.y;
    fp = new Position(x, y);
}

Position returnNP() {
    return intP;
}
float returnNP_x(){
    return intP.x;
}
float returnNP_y(){
    return intP.y;
}
}
*/
