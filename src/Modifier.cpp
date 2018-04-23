//
//  Modifier.cpp
//  dogwalker
//
//  Created by Togo Kida on 2018/04/21.
//

#include "Modifier.hpp"


void Modifier::setup(float _xpos, float _ypos, float _radius, int _naxNum, int _ID){
    
    /*
    x = xpos;
    y = ypos;
    p = new Position(xpos, ypos);
    r = radius;
    id = ID;
    for(int i = 0; i<gridNum; i++) {
        d[i] = new Position(0, 0);
        close[i] = new Position(0, 0);
        temp[i] = new Position(0, 0);
    }
    */
    
    
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
    
    nullPos.setup(0, 0);
    
    /*
     wrote code equavalent to this in the above: 
     Position d[] = new Position[gridNum];//for storing the distance of
     Position temp[] = new Position[gridNum];
     Position close[] = new Position[gridNum];//x is used for distance, y is used for storing the ID number.
     Position nullPos = new Position(-1, -1);//null position
     */
}

void Modifier::draw(){
    /*
     //fill(0, 255, 0);
     //ellipse(x, y, r, r);
     sort();
     getClosest();
     sendT();
     //println(d[0].x);
     }
     
     void setP(Position pos) {
     x = p.x;
     y = p.y;
     p = new Position(pos);
     
     */
}

void Modifier::setP(Position _pos){
    /*
    x = p.x;
    y = p.y;
    p = new Position(pos);
     */
}

void Modifier::set(Position _pos){
     p = _pos;
}

void Modifier::getDistance(){
    /*
     for(int i = 0; i<numGrid; i++) {
     d[i].x = dist(p, grid.agent[i].fp);
     d[i].y = grid.agent[i].getID();
     }
     */
}


Position Modifier::compareR(Position _n){
    
    /*
     if(r/2 >= n.x) {
     //println(n.y);
     //fill(0, 0, 255);
     //rect(grid.agent[(int)n.y].fp.x, grid.agent[(int)n.y].fp.y, 10, 10);
     //println("yay");
     return n;
     }
     else
     return nullPos;
     */
    
}

void Modifier::sort(){
    /*
    getDistance();
    for(int i = 0; i<gridNum; i++) {
        close[i].set(compareR(d[i]));
    }
     */
}

void Modifier::getClosest(){
    /*
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
     
     */
    
}

int Modifier::getId(){
    return id;
}

void Modifier::drawController(){
    /*
     noFill();
     stroke(255, 0, 0);
     //ellipse(p.x, p.y, 10, 10);
     */
}

void Modifier::sendT(){
    /*
    //println(closest.y);
    for(int i = 0; i<gridNum; i++) {
        if((int)close[i].y > 0) {
            grid.agent[(int)close[i].y].tSet(p);
            grid2.agent[(int)close[i].y].tSet(p);
            //grid.agent[(int)close[i].y].maxVSet(2);
            //fill(255, 0, 0);
            //ellipse(grid.agent[(int)close[i].y].fp.x, grid.agent[(int)close[i].y].fp.y, 4, 4);
            //println("yay");
        }
    }
     */
}






