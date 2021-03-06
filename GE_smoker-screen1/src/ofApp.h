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
    float getDefaultSmokeVelocity();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		

    float sensorValue, sv, targetSV;
    int lastRot;
    int readSensor;
    string serialData;
    
    DataReader dataReader, dataReader2;
    
    SensorReading smokeVelocity, humidity;
    
    Graph graph;
    
    uiManager ui;
    
    
    
};

