#include "ofMain.h"
#include "ofApp.h"
#include "ofxWatchdog.h"

//========================================================================
int main( ){

    ofxWatchdog::watch(3000, true, true, true);
    
	ofSetupOpenGL(1920,1080, OF_FULLSCREEN);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp( new ofApp());

}
