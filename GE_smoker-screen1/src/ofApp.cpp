#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
   // dataReader.setup("tty.usbserial-DA017U1V", 2);
    dataReader.setup("tty.usbserial-DA017U1C", 2, "|");
    
    //create the widgets
    smokeVelocity.setup("SMOKE VELOCITY", "ft/min", ui.red, &ui.fontGE170B, &ui.fontGE85B, &ui.fontGE54B);
    humidity.setup("RELATIVE HUMIDITY", "%", ui.blue, &ui.fontGE170B, &ui.fontGE85B, &ui.fontGE54B);
    
    //setup the graph
    graph.setLeftAxis("Smoke Velocity (f/m)", -100, 100, 20);
    graph.setRightAxis("Relative Humidity (%)", 0, 100, 10);
    graph.setup("graphData.xml");
    graph.clearData();
    graph.addLine(graph.LEFT, ui.red);
    graph.addLine(graph.RIGHT, ui.blue);

    ui.startTimer();
    
    lastRot = 0;
    sv = 0;
    targetSV = 0;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    ui.update();
    
    dataReader.update();
    
    //draw everything to the screen FBO
    ui.screenFbo.begin();
    
    int readTime = 4000;
    
    float h;
    int rot;
    if(dataReader.setupSuccess){
        if(ui.timePassed > readTime){
            rot = dataReader.sensorValues[1];
        }
        h = dataReader.sensorValues[0];
        
    }
    else{
        //generate some rando values...
        //sv = graph.getTestData(graph.LEFT);
        h = graph.getTestData(graph.RIGHT);
    }
    
    //get smoke velocity reading
    
    //update graph every second
    if(ui.timePassed > readTime){
        if(dataReader.setupSuccess){
            //d is the diameter of the blade in feet
            float d = 3.5/12;
            // C is circumference, over 60 to calculate movement per minute
            float C = (M_PI * d);
            targetSV = (C*rot/360)*(60/(readTime/1000));
        }
        else{
            targetSV = getDefaultSmokeVelocity();
            
        }
        
       // cout<<"read value 1: "<<rot<<endl;
        //add data to graph
        graph.pushDataToLeftAxis(sv);
        graph.pushDataToRightAxis(h);
        
        ui.resetTimer();
    }
    
    //if 0, randomize
    if(targetSV == 0)
        targetSV = getDefaultSmokeVelocity();
    
    //tween to target sv
    cout<<"targetSV: "<<targetSV<<endl;
    sv += (targetSV - sv)/100;
    
    //update smoke velocity value
    smokeVelocity.update(ofToString(abs(sv),0));
    
    smokeVelocity.draw(100, 640);
    
    humidity.update(ofToString(h,2));
    humidity.draw(100, 940);

    
    graph.draw(780, 470);
    ui.screenFbo.end();
    //*********************************
    
}

float ofApp::getDefaultSmokeVelocity(){
    return ofRandom(7,20);
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

