#pragma once

#include "ofMain.h"
#include "DataReader.h"
#include "SensorReading.h"

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
		
		ofTrueTypeFont fontGE170B, fontGE85B, fontGE54B;

    float sensorValue;
    int readSensor, w, h;
    string serialData;
    
    DataReader dataReader, dataReader2;
    ofFbo screenFbo;
    ofImage screenImage;
    ofPixels * screenPixels;
    bool isFullScreen;
    
    SensorReading smokeVelocity, humidity;
    ofColor red, blue, green, orange, purple;
    
};

