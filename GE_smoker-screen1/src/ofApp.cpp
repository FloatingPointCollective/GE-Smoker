#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	
	ofBackground(255);
	ofSetLogLevel(OF_LOG_VERBOSE);
	
	//font.loadFont("DIN.otf", 20);
    //load all fonts to be used
    float fontScale = .75;
    fontGE170B.loadFont("GEInsBol", 170*fontScale);
    fontGE85B.loadFont("GEInsBol", 85*fontScale);
    fontGE54B.loadFont("GEInsBol", 54*fontScale);
    
    dataReader.setup("tty.usbserial-DA017U1V", 2);
    dataReader2.setup("tty.usbserial-DA017U1C", 1);
    
    w = 1920;
    h = 1080;
    
    screenFbo.allocate(w, h);
    screenImage.allocate(w, h, OF_IMAGE_COLOR);
    
    isFullScreen = true;
    
    //define colors
    red.setHex(0xd1202a);
    blue.setHex(0x0c6bbd);
    
    //create the widgets
    smokeVelocity.setup("SMOKE VELOCITY", "ft/min", red, &fontGE170B, &fontGE85B, &fontGE54B);
    humidity.setup("RELATIVE HUMIDITY", "%", blue, &fontGE170B, &fontGE85B, &fontGE54B);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    dataReader.update();
    dataReader2.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    //draw everything to the screen FBO
    ofBackground(255);
    
    screenFbo.begin();
    //ofSetColor(0);
    
	string msg;
    msg +="OF App\n\n";
    msg +="Device 1:\n";
    msg += "RH: " + ofToString(dataReader.sensorValues[0]) + "\n";
    msg += "Temp: " + ofToString(dataReader.sensorValues[1]) + "\n\n";
    msg +="Device 2:\n";
    msg += "Temp: " + ofToString(dataReader2.sensorValues[0]) + "\n";
    
	//fontGE85B.drawString(msg, 50, 100);
    
    smokeVelocity.update("69.9");
    smokeVelocity.draw(100, 640);
    
    humidity.update("69.9");
    humidity.draw(100, 940);
    
    screenFbo.end();
    //*********************************
    
    //update screen image from FBO
    screenFbo.readToPixels(screenImage);
    //scale the screen image based on the screen size
    int newHeight = (ofGetWidth()*h)/w;
    screenImage.resize(ofGetWidth(), newHeight);
    
    //don't forget to reset the color to white tho!
    ofSetColor(255);
    screenImage.draw(0,0);
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){ 
    switch(key){
        case 'f':
            isFullScreen = ! isFullScreen;
            ofSetFullscreen(isFullScreen);
            break;
    }
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

