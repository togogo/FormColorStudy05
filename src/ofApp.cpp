#include "ofApp.h"


/*
 Let's see what happens if I visualize Modifier...
 I hope it works...
 
 Or maybe... I should start working from Vehicle...
 and make that follow my mouse or something....
 
..
 
 I did visualize Modifer and Grid.
 Nothing really happens.
 
 */

//--------------------------------------------------------------
void ofApp::setup(){
    testGrid.setup(30, 30, 10, 30);
    testMod1.setup((int)ofRandom(0, ofGetWidth()), (int)ofRandom(0, ofGetHeight()), (int)ofRandom(100, 300), 100, 1);
    testMod2.setup((int)ofRandom(0, ofGetWidth()), (int)ofRandom(0, ofGetHeight()), (int)ofRandom(100, 300), 100, 2);
    testMod3.setup((int)ofRandom(0, ofGetWidth()), (int)ofRandom(0, ofGetHeight()), (int)ofRandom(100, 300), 100, 3);
}

//--------------------------------------------------------------
void ofApp::update(){

    rad1 += 0.01;
    rad2 = ofRandom(-TWO_PI, TWO_PI);
}

//--------------------------------------------------------------
void ofApp::draw(){

    testGrid.draw();
    testMod1.drawController();
    testMod2.drawController();
    testMod3.drawController();
    /*
    //base circle
    
    ofNoFill();
    ofSetColor(255, 255, 255);
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, baseR);
    
    //satelite circle
    ofFill();
    ofSetColor(255, 0, 0);
    ofDrawCircle(baseR*cos(rad1) + ofGetWidth()/2, baseR*sin(rad1) + ofGetHeight()/2, sat1R);
    
    ofNoFill();
    ofSetColor(255, 0, 0);
    ofDrawCircle(baseR*cos(rad1) + ofGetWidth()/2, baseR*sin(rad1) + ofGetHeight()/2, sat2R);
    
    //satelite of satelite circle
    ofFill();
    ofSetColor(255, 0, 0);
    ofDrawCircle(sat2R*cos(rad2)+ baseR*cos(rad1) + ofGetWidth()/2, sat2R*sin(rad2) + baseR*sin(rad1) + ofGetHeight()/2, satsat1R);
    
    //line from base to satelite of satelite
    
    ofSetColor(0, 0, 255);
    ofDrawLine(ofGetWidth()/2, ofGetHeight()/2, sat2R*cos(rad2)+ baseR*cos(rad1) + ofGetWidth()/2, sat2R*sin(rad2) + baseR*sin(rad1) + ofGetHeight()/2);
     */
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
