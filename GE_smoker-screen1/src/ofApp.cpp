#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
   // dataReader.setup("tty.usbserial-DA017U1V", 2);
    dataReader.setup("tty.usbserial-DA017U1C", 2, "|");
    
    //create the widgets
    smokeVelocity.setup("SMOKE VELOCITY", "ft/min", ui.red, &ui.fontGE170B, &ui.fontGE85B, &ui.fontGE54B);
    humidity.setup("RELATIVE HUMIDITY", "%", ui.blue, &ui.fontGE170B, &ui.fontGE85B, &ui.fontGE54B);
    
    //setup the graph
    graph.setLeftAxis("Smoke Velocity (f/m)", -1000, 1000, 200);
    graph.setRightAxis("Relative Humidity (%)", 0, 100, 10);
    graph.setup("graphData.xml");
    graph.clearData();
    graph.addLine(graph.LEFT, ui.red);
    graph.addLine(graph.RIGHT, ui.blue);

    ui.startTimer();
    
    lastRot = 0;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    ui.update();
    
    
    
    dataReader.update();
    //dataReader2.update();
    
    //draw everything to the screen FBO
    ui.screenFbo.begin();
    
    //ofBackground(255);
    
    float sv, h;
    int rot;
    if(dataReader.setupSuccess){
        if(ui.timePassed > 500){
            rot = dataReader.sensorValues[1];
        }
        h = dataReader.sensorValues[0];
        
    }
    else{
        //generate some rando values...
        sv = graph.getTestData(graph.LEFT);
        h = graph.getTestData(graph.RIGHT);
    }
    
    
    //update graph every second
    if(ui.timePassed > 500){
        //sv = (lastRot - rot)/100;
        //sv = rot/100;
        
        if(dataReader.setupSuccess){
        //d is the diameter of the blade in feet
        float d = 3.5/12;
        // C is circumference, over 60 to calculate movement per minute
        float C = (M_PI * d);
        sv = (C*rot/360)*60;
        }
        
        //lastRot = rot;
        
        
        cout<<"read value 1: "<<rot<<endl;
        //add data to graph
        graph.pushDataToLeftAxis(sv);
        graph.pushDataToRightAxis(h);
        
        smokeVelocity.update(ofToString(sv,1));
        
        ui.resetTimer();
        
        
    }
    
    
    smokeVelocity.draw(100, 640);
    
    humidity.update(ofToString(h,2));
    humidity.draw(100, 940);

    
    graph.draw(780, 470);
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

