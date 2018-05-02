//
//  Grid.cpp
//  dogwalker
//
//  Created by Togo Kida on 2018/04/24.
//

#include "Grid.hpp"



void Grid::setup(int _w, int _h, int _m, int _delayer){
    
    
     gridWidth = _w;
     gridHeight = _h;
     maxV = _m;
     d = _delayer;
     numGrid = gridWidth*gridHeight;
     for(int i = 0; i < numGrid; i++) {
         Agent tempAgent;
         Position tempP;
         tempP.setup(0, 0);//maybe need to revisit here
         tempAgent.setup(i, 0, 0, tempP, d, maxV);
         agent.push_back(tempAgent);
     }
    
    
}

void Grid::draw(){
    for(int i = 0; i<numGrid; i++) {
        Position p = new Position(ofGetMouseX(), ofGetMouseY());
        agent[i].maxVSet(maxV);
     //agent[i].aSet(0);
     //agent[i].tSet(p);
     //deploy();
        agent[i].draw();
     //println("yay");
    }
    deploy();
     
     //draw horizontal grid
     //for(int i = 0; i<numGrid -3; i++) {
     //if(i >= 0 && i<gridWidth-3) {
     //noStroke();
     //beginShape(POLYGON);
     //fill(255, 0, 0);
     //vertex(agent[i].intP);
     //fill(0, 255, 0);
     //vertex(agent[i+1].intP);
     //fill(0, 0, 255);
     //vertex(agent[i+2].intP);
     //fill(0, 255, 255);
     //vertex(agent[i+3].intP);
     //endShape();
     //}
     //for(int j = 2; j<=gridWidth; j++) {
     //if(i >= gridWidth*(j-1) && i < gridWidth*j - 3) {
     //beginShape(POLYGON);
     //fill(255, 255, 0);
     //vertex(agent[i].intP);
     //fill(255, 0, 255);
     //vertex(agent[i+1].intP);
     //fill(0, 0, 255);
     //vertex(agent[i+2].intP);
     //fill(0, 255, 0);
     //vertex(agent[i+3].intP);
     //endShape();
     //}
     //}
     //}
     
     //color square
     //noStroke();
     //noFill();
     //stroke(0, 100);
     ofSetColor(255, 255, 255, 50);
     for(int i = 0; i<numGrid - gridWidth - 1; i++) {
     if(i >=0 && i< gridWidth - 1){
     noFill();
     beginShape(LINE_LOOP);
     stroke(0,200);
     vertex(agent[i].intP);
     stroke(255, 50);
     vertex(agent[i+1].intP);
     vertex(agent[i+gridWidth+1].intP);
     vertex(agent[i+gridWidth].intP);
     }
     for(int j = 2; j<=gridWidth; j++) {
     if(i >=gridWidth*(j-1) && i< gridWidth*j- 1){
     beginShape(LINE_LOOP);
     //fill(0,100);
     stroke(0,200);
     vertex(agent[i].intP);
     //fill(255,100);
     stroke(255,50);
     vertex(agent[i+1].intP);
     vertex(agent[i+gridWidth+1].intP);
     vertex(agent[i+gridWidth].intP);
     }
     }
     endShape();
     
     }
     //draw vertical lines
     //for(int i = 0; i<numGrid - 3*gridWidth; i++) {
     //beginShape(POLYGON);
     //fill(0, 0, i/3);
     //vertex(agent[i].intP);
     //vertex(agent[i+gridWidth].intP);
     //vertex(agent[i+2*gridWidth].intP);
     //endShape();
     //}
     
     //fill(255, 0, 0);
     //ellipse(agent[99].fp.x, agent[99].fp.y, 5 , 5);
     
    
    
}

void Grid::deploy(){
    for(int i = 0; i < numGrid; i++){
         if(i >= 0 && i<gridWidth){
             agent[i].fp.setup((ofGetWidth()/gridWidth)*i + (ofGetWidth()/gridWidth)*0.5, (ofGetHeight()/gridHeight)*0.5);
         }
        for(int j = 2; j<=gridWidth; j++){
            if(i >= gridWidth*(j-1) && i < gridWidth*j){
                agent[i].fp.setup((ofGetWidth()/gridWidth)*(i-gridWidth*(j-1))+(ofGetWidth()/gridWidth)*0.5, (ofGetHeight()/gridHeight)*(j-1) + (ofGetHeight()/gridHeight)*0.5);
            }
        }
     }
}
