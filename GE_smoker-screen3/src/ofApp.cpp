#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    dataReader.setup("tty.usbserial-DA017U1V", 2);
    dataReader2.setup("tty.usbserial-DA017U1C", 1);
    
    //create the widgets
    meatTemp1.setup("MEAT TEMP 1", "f", ui.red, &ui.fontGE170B, &ui.fontGE85B, &ui.fontGE54B);
    meatTemp2.setup("MEAT TEMP 2", "f", ui.orange, &ui.fontGE170B, &ui.fontGE85B, &ui.fontGE54B);

    ui.setup(3);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    dataReader.update();
    dataReader2.update();
    
    ui.update();
    
    //draw everything to the screen FBO
    ui.screenFbo.begin();
    
    float t1, t2;
    if(dataReader.setupSuccess){
        t1 = dataReader.sensorValues[0];
        t2 = dataReader.sensorValues[1];
    }
    else{
        //generate some rando values...
        t1 = ofRandom(150,450);
        t2 = ofRandom(150,450);
    }
    
    meatTemp1.update(ofToString(t1,1)+ui.degreeSymbolUnicode);
    meatTemp2.update(ofToString(t2,1)+ui.degreeSymbolUnicode);
    
    meatTemp1.draw(100, 640);
    meatTemp2.draw(100, 940);
    
    ui.screenFbo.end();
    //*********************************
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    //update screen image from FBO
    ui.draw();
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

