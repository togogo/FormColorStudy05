//
//  Vehicle.cpp
//  dogwalker
//
//  Created by Togo Kida on 2018/04/07.
//


#include "Vehicle.hpp"

void Vehicle::setup(ofVec2f _p,float _angle,float _magnitude, float _m, float _maxA, float _maxS, float _maxT){
    
    //location=new Position(p);
    location = _p;
    velocity.setup(location, _angle, _magnitude);
    acceleration = velocity;
    steer = velocity;
    controller.setup(ofRandom(0, ofGetScreenWidth()), ofRandom(0, ofGetScreenHeight()), 5, 5);
    vSize = 15;//not implemented for this program
    mass = _m;
    maxAccel = _maxA;
    maxSpeed = _maxS;
    minSpeed = maxSpeed/2;
    maxTurn= _maxT;
    temp.set(100, 100);
    closest.set(100, 1);
    
    for(int i = 0; i<contNum; i++) {
        ofVec2f tempPos;
        tempPos.set(0, 0);
        d.push_back(tempPos);
    }
}

void Vehicle::update(){
    
    //the if statement part might be mistaken...in case of error, fix here...
    
    steer = seek();//using seek behavior against target
    acceleration.setup(steer);//apply the steering force
    acceleration.p = location;
    acceleration.m = steer.m / mass;//acceleration=force / mass
    if(velocity.m > 0 ){ //prevent 0 velocity rotation
        velocity = velocity.add(acceleration);//time-step force to the velocity vector
    }
    velocity.m = constrain(velocity.m, minSpeed, maxSpeed);//constrain the velocity vector to max vehicle speed
    Position tempPos;
    tempPos.setup(location);
    tempPos = tempPos.displace(velocity.a,velocity.m);  //set new position based on velocity vector
    location.set(tempPos.x, tempPos.y);
    velocity.p=location;
    
}

float Vehicle::constrain(float _x, float _a, float _b){
        if(_x < _a) {
            return _a;
        }
        else if(_b < _x) {
            return _b;
        }
        else
            return _x;
}

Vec Vehicle::seek(){
    
     //desired vector would be a straight line from the vehicle to the target
    Vec tempVec;
    desired.setup(location, tempVec.getHeading(location,controller.p), tempVec.dist(location,controller.p));
    
    Vec desiredTruncate;
    desiredTruncate.setup(desired);
    
     //desiredTruncate.m=dist(desired.p,desired.endPoint())/(10/mass);
    
    ofVec2f tempDesiredEndPoint;
    Position tempPos;
    tempPos = desired.endPoint();
    tempDesiredEndPoint.set(tempPos.x, tempPos.y);
    desiredTruncate.m = tempVec.dist(desired.p, tempDesiredEndPoint)/10;
    //wait...desired.p is ofVec2f
    //oh yeah, so tem
    
     //desiredTruncate.m=maxSpeed*.4;    //alternative truncation
     //drawVector(desiredTruncate);
     //steer the currenty velocity towards a particular point on the desired vector
    
    Vec steer;
    Position tempSteerPos;
    tempSteerPos = velocity.endPoint();
    steer.setup(tempSteerPos.x, tempSteerPos.y, tempVec.getHeading(velocity.endPoint(), desiredTruncate.endPoint()), tempVec.dist(velocity.endPoint(), desiredTruncate.endPoint()));
    
     //constrain the steering to maximum vehicle force
     steer.m = constrain(desired.m, 0, maxAccel);
     return steer;
    
    
    
}

void Vehicle::draw(){
    
     //drawVehicle();
     //drawController();
     //drawAllVectors();
     updateController();
     drawController();
     //rapController();
    
}

void Vehicle::drawAllVectors(){
    /*
     drawVector(velocity,255,0,0,10);
     drawVector(steer,0,255,255,10);
     drawVector(desired,255,255,0);
     */
}

void Vehicle::drawVehicle(){
    /*
     stroke(255);
     //line(location.displace(velocity.a,vSize).x,location.displace(velocity.a,vSize).y,location.displace(velocity.a,-1*vSize).x,location.displace(velocity.a,-1*vSize).y);
     //ellipseMode(CENTER);
     //noStroke();
     //fill(light_orange);
     rect(location.x,location.y, 2, 2);
     //println(location.x);
     //fill(255, 0, acceleration.m);
     //ellipse(location.x, location.y, rad, rad);
     */
}

void Vehicle::drawController(){
    /*
     noFill();
     //stroke(255, 255, 0);
     //ellipse(controller.p.x, controller.p.y, rad, rad);
     //println(d.length);
     //fill(0, 0, 255);
     //ellipse(m[placeHolder].x, m[placeHolder].y, rad, rad);
     */
}

ofVec2f Vehicle::sort(){
    /*
     temp = compare(d[1], d[2]);
     for(int i =  3; i<contNum; i++) {
     temp = compare(temp, d[i]);
     }
     return temp;
     */
}

void Vehicle::updateController(){
    /*
     //IMPLEMENT!! this part is from Casey_imitation program
     getDistance();
     closest = sort();
     placeHolder = (int)closest.y;
     //controller.p.x = m[placeHolder].p.x;
     //controller.p.y = m[placeHolder].p.y;
     //controller.p = m[placeHolder].p;
     //controller.p.x++;
     
     //println(randomAng);
     //controller = controller.add(randomAng, 0.5);
     //controller.p = controller.p.displace(random(0, 360), controller.m*4);
     //drawVector(controller,255,0,0);
     
     //if random flow mode is true .....
     
     //controller.p.x += random(-5, 5);
     //controller.p.y += random(-5, 5);
     */
}

void Vehicle::getDistance(){
    
     for(int i = 1; i<contNum; i++) {
    /*
     //oh, ok I get it... another new class here.... Modifier...
     d[i].x = ofDist(location.x, location.y, m[i].p.x, m[i].p.y);
     d[i].y = m[i].getId();
     */
     }

}

ofVec2f Vehicle::compare(Position m, Position n){
    /*
     if(m.x > n.x) {
     return n;
     }
     if(m.x < n.x) {
     return m;
     }
     else
     return null;
     */
}

void Vehicle::rapController(){
    /*
     if(controller.p.x > width) {
     controller.p.x = 0;
     }
     if(controller.p.x < 0) {
     controller.p.x = width;
     }
     if(controller.p.y > height) {
     controller.p.y = 0;
     }
     if(controller.p.y < 0) {
     controller.p.y = height;
     }
     
     */
}


