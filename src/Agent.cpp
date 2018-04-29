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


