#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
   // dataReader.setup("tty.usbserial-DA017U1V", 2);
    dataReader.setup("tty.usbserial-DA017U1C", 2, "|");
    
    //create the widgets
    smokeVelocity.setup("SMOKE VELOCITY", "ft/min", ui.red, &ui.fontGE170B, &ui.fontGE85B, &ui.fontGE54B);
    humidity.setup("RELATIVE HUMIDITY", "%", ui.blue, &ui.fontGE170B, &ui.fontGE85B, &ui.fontGE54B);
    
    //setup the graph
    graph.setLeftAxis("Smoke Velocity (f/m)", 0, 100, 10);
    graph.setRightAxis("Relative Humidity (%)", 0, 100, 10);
    graph.setup("graphData.xml");
    graph.clearData();
    graph.addLine(graph.LEFT, ui.red);
    graph.addLine(graph.RIGHT, ui.blue);

    ui.startTimer();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    //ui.update();
    
    
    
    dataReader.update();
    //dataReader2.update();
    
    //draw everything to the screen FBO
    ui.screenFbo.begin();
    
    ofBackground(255);
    
    float sv, h;
    if(dataReader.setupSuccess){
        sv = dataReader.sensorValues[1];
        h = dataReader.sensorValues[0];
    }
    else{
        //generate some rando values...
        sv = graph.getTestData(graph.LEFT);
        h = graph.getTestData(graph.RIGHT);
    }
    
    smokeVelocity.update(ofToString(sv,1));
    smokeVelocity.draw(100, 640);
    
    humidity.update(ofToString(h,2));
    humidity.draw(100, 940);
    
    //update graph every second
    if(ui.timePassed > 500){
    //add data to graph
    graph.pushDataToLeftAxis(sv);
    graph.pushDataToRightAxis(h);
        ui.resetTimer();
    
    }
    graph.draw(780, 470);
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

