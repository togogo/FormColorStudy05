#pragma once

#include "ofMain.h"
#include "Vec.hpp"
#include "Vehicle.hpp"
#include "Position.hpp"
#include "Modifier.hpp"
#include "Grid.hpp"
#include "Agent.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    
        //radii
        float baseR = 200;
        float sat1R = 10;
        float sat2R = 50;
    
        float satsat1R = 10;
    
        float rad1 = 0.0;
        float rad2 = 0.0;
    
    Grid testGrid;
    Modifier testMod1;
    Modifier testMod2;
    Modifier testMod3;
    
    Vehicle testVehicle1;
    Vehicle testVehicle2;
    Vehicle testVehicle3;
    
    
    /*
     //should look into this stuff???
     
     
     int contNum = 4;
     Modifier m[] = new Modifier[contNum];
     
     for(int i = 0; i<contNum; i++) {
     m[i] = new Modifier((int)random(width), (int)random(height), (int)random(200, 400), 100, i);
     }
     
     Under draw(), do this:
     for(int i = 0; i<contNum; i++) {
     m[i].drawController();
     }
     */
		
};
