#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    dataReader.setup("tty.usbserial-DA017N2K", 2, ":");
    
    //create the widgets
    meatTemp1.setup("MEAT TEMP 1", "f", ui.red, &ui.fontGE170B, &ui.fontGE85B, &ui.fontGE54B);
    meatTemp2.setup("MEAT TEMP 2", "f", ui.orange, &ui.fontGE170B, &ui.fontGE85B, &ui.fontGE54B);

    ui.setup(3);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    dataReader.update();
    
    ui.update();
    
    //draw everything to the screen FBO
    ui.screenFbo.begin();
    
    float t1, t2;
    if(dataReader.setupSuccess){
        t1 = ui.celsiusToFahrenheit(dataReader.sensorValues[0]);
        t2 = ui.celsiusToFahrenheit(dataReader.sensorValues[1]);
    }
    else{
        //generate some rando values...
        t1 = ofRandom(0,220);
        t2 = ofRandom(150,450);
    }
    
    meatTemp1.update(ofToString(t1,1)+ui.degreeSymbolUnicode);
    meatTemp2.update(ofToString(t2,1)+ui.degreeSymbolUnicode);
    
    meatTemp1.draw(100, ui.readingSpacing);
    meatTemp2.draw(100, 650);
    
    //THE DIAL
    int targetTemp = 200;
    dial.update(t1/targetTemp);
    //dial.update(0);
    dial.draw(1284,642);
    
    ui.screenFbo.end();
    //*********************************
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    //update screen image from FBO
    ui.draw();
    
   // dial.draw(1300,642);
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){ 
    ui.keyPressed(key);
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

