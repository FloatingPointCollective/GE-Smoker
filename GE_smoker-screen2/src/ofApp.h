#pragma once

#include "ofMain.h"
#include "DataReader.h"
#include "SensorReading.h"
#include "uiManager.h"
#include "Graph.h"

class ofApp : public ofBaseApp{
	
	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    DataReader dataReader, dataReader2;
    
    SensorReading chamberTemp1, chamberTemp2, chamberTemp3;
    
    uiManager ui;
    
    Graph graph;
    
};

