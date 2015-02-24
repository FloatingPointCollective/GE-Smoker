#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	
	ofBackground(255);
	ofSetLogLevel(OF_LOG_VERBOSE);
	
	font.loadFont("DIN.otf", 20);
    
    dataReader.setup("tty.usbserial-DA017U1V", 2);
    dataReader2.setup("tty.usbserial-DA017U1C", 1);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    dataReader.update();
    dataReader2.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    ofSetColor(255);
	string msg;
    msg +="OF App\n\n";
    msg +="Device 1:\n";
    msg += "RH: " + ofToString(dataReader.sensorValues[0]) + "\n";
    msg += "Temp: " + ofToString(dataReader.sensorValues[1]) + "\n\n";
    
    msg +="Device 2:\n";
    msg += "Temp: " + ofToString(dataReader2.sensorValues[0]) + "\n";
    
	font.drawString(msg, 50, 100);
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){ 
   
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){ 
	
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
	
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
void ofApp::windowResized(int w, int h){
	
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
	
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
	
}

