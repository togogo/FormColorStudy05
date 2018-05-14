//
//  Modifier.cpp
//  dogwalker
//
//  Created by Togo Kida on 2018/04/21.
//

#include "Modifier.hpp"


void Modifier::setup(float _xpos, float _ypos, float _radius, int _naxNum, int _ID){
    
    //I don't know if this will work...
    grid.setup(gridWidth, gridHeight, 30, del);
    grid2.setup(gridWidth, gridHeight, 30, del/2);
    x = _xpos;
    y = _ypos;
    p.setup(_xpos, _ypos);
    r = _radius;
    id = _ID;
    
    for(int i = 0; i<gridNum; i++) {
        Position tempD;
        Position temptemp;
        Position tempClose;
        tempD.setup(0, 0);
        temptemp.setup(0, 0);
        tempClose.setup(0, 0);
        d.push_back(tempD);
        temp.push_back(temptemp);
        close.push_back(tempClose);
    }
    
    nullPos.setup(-1, -1);

}

void Modifier::draw(){
    
     //fill(0, 255, 0);
     //ellipse(x, y, r, r);
     sort();
     getClosest();
     sendT();
     //println(d[0].x);
     }

void Modifier::setP(Position _pos){
    
    //is this guy even used?
    x = p.x;
    y = p.y;
    p.setup(_pos.x, _pos.y);
    
}

void Modifier::set(Position _pos){
     p = _pos;
}

void Modifier::getDistance(){
    
     for(int i = 0; i < numGrid; i++) {
         d[i].x = ofDist(p.x, p.y, grid.agent[i].fp.x, grid.agent[i].fp.y);
         d[i].y = grid.agent[i].getID();
     }
    
}


Position Modifier::compareR(Position _n){
    
    
     if(r/2 >= _n.x) {
     //println(n.y);
     //fill(0, 0, 255);
     //rect(grid.agent[(int)n.y].fp.x, grid.agent[(int)n.y].fp.y, 10, 10);
     //println("yay");
         return _n;
     }
     else
     return nullPos;
    
    
}

void Modifier::sort(){
    getDistance();
    for(int i = 0; i < gridNum; i++) {
        close[i].setup(compareR(d[i]));
    }
}

void Modifier::getClosest(){
    
    getDistance();
    //println(sort().x);
    
    //if(sort().y > 0) {
    //fill(0, 0, 255);
    //rect(grid.agent[(int)sort().y].fp.x, grid.agent[(int)sort().y].fp.y, 10, 10);
    //close[(int)sort().y] = new Position(sort());
    //println("yay");
     
     //if(keyPressed == true) {
     //if(key == 'd') {
     //print("the value of d[0].x is: ");
     //println(d[0].x);
     //}
     //if(key == 'c') {
     //print("the value of closest.y is: ");
     //print((int)closest.y);
     //print(" the id if closest object is: ");
     //println(grid.agent[(int)closest.y].getID());
     //}
     //}
    
    
}

int Modifier::getId(){
    return id;
}

void Modifier::drawController(){
    
     ofNoFill();
     ofSetColor(255, 0, 0);
     ofDrawCircle(p.x, p.y, 10);
    
}

void Modifier::sendT(){
    
    //println(closest.y);
    for(int i = 0; i < gridNum; i++) {
        if((int)close[i].y > 0) {
            grid.agent[(int)close[i].y].tSet(p);
            grid2.agent[(int)close[i].y].tSet(p);
            //grid.agent[(int)close[i].y].maxVSet(2);
            //fill(255, 0, 0);
            //ellipse(grid.agent[(int)close[i].y].fp.x, grid.agent[(int)close[i].y].fp.y, 4, 4);
            //println("yay");
        }
    }
    
}






