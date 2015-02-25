#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    dataReader.setup("tty.usbserial-DA017U1V", 2);
    dataReader2.setup("tty.usbserial-DA017U1C", 1);
    
    //create the widgets
    chamberTemp1.setup("CHAMBER TEMP 1", "f", ui.green, &ui.fontGE170B, &ui.fontGE85B, &ui.fontGE54B);
    chamberTemp2.setup("CHAMBER TEMP 2", "f", ui.orange, &ui.fontGE170B, &ui.fontGE85B, &ui.fontGE54B);
    chamberTemp3.setup("CHAMBER TEMP 3", "f", ui.purple, &ui.fontGE170B, &ui.fontGE85B, &ui.fontGE54B);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    dataReader.update();
    dataReader2.update();
    
    //draw everything to the screen FBO
    ui.screenFbo.begin();
    
    chamberTemp1.update("666.1"+ui.degreeSymbolUnicode);
    chamberTemp2.update("666.2"+ui.degreeSymbolUnicode);
    chamberTemp3.update("666.3"+ui.degreeSymbolUnicode);
    
    string msg;
    msg +="OF App\n\n";
    msg +="Device 1:\n";
    msg += "RH: " + ofToString(dataReader.sensorValues[0]) + "\n";
    msg += "Temp: " + ofToString(dataReader.sensorValues[1]) + "\n\n";
    msg +="Device 2:\n";
    msg += "Temp: " + ofToString(dataReader2.sensorValues[0]) + "\n";
    
    //fontGE85B.drawString(msg, 50, 100);
    
    chamberTemp1.draw(100, 360);
    chamberTemp2.draw(100, 640);
    chamberTemp3.draw(100, 940);
    
    ui.screenFbo.end();
    //*********************************
    
    ui.update();
    
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

