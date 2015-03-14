#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    dataReader.setup("tty.usbserial-DA017U1V", 2, ":");
    dataReader2.setup("tty.usbserial-DA017N3P", 1, ":");
    
    //create the widgets
    chamberTemp1.setup("CHAMBER TEMP 1", "f", ui.green, &ui.fontGE170B, &ui.fontGE85B, &ui.fontGE54B);
    chamberTemp2.setup("CHAMBER TEMP 2", "f", ui.orange, &ui.fontGE170B, &ui.fontGE85B, &ui.fontGE54B);
    chamberTemp3.setup("CHAMBER TEMP 3", "f", ui.purple, &ui.fontGE170B, &ui.fontGE85B, &ui.fontGE54B);

    //setup the graph
    graph.setBothAxis("Temperature (F)", 80, 300, 20);
    graph.setup("graphData.xml");
    graph.clearData();
    graph.addLine(graph.LEFT, ui.green);
    graph.addLine(graph.LEFT, ui.orange);
    graph.addLine(graph.LEFT, ui.purple);
    ui.setup(2);
    ui.startTimer();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    dataReader.update();
    dataReader2.update();
    
    ui.update();

    int readTime = 4000;
    //draw everything to the screen FBO
    ui.screenFbo.begin();
    
    float t1, t2, t3;
    if(dataReader.setupSuccess){
        t1 = ui.celsiusToFahrenheit(dataReader.sensorValues[0]);
        t2 = ui.celsiusToFahrenheit(dataReader.sensorValues[1]);
        t3 = ui.celsiusToFahrenheit(dataReader2.sensorValues[0]);
    }
    else{
        //generate some rando values...
        t1 = graph.getTestData(graph.LEFT);
        t2 = graph.getTestData(graph.LEFT);
        t3 = graph.getTestData(graph.LEFT);
    }
    
    chamberTemp1.update(ofToString(t1,1)+ui.degreeSymbolUnicode);
    chamberTemp2.update(ofToString(t2,1)+ui.degreeSymbolUnicode);
    chamberTemp3.update(ofToString(t3,1)+ui.degreeSymbolUnicode);

    if(ui.timePassed > readTime){
        ui.resetTimer();
        graph.pushDataToLeftAxis(t1,0);
        graph.pushDataToLeftAxis(t2,1);
        graph.pushDataToLeftAxis(t3,2);
    }
    graph.draw(780, 400);
    
    chamberTemp1.draw(100, 360);
    chamberTemp2.draw(100, 640);
    chamberTemp3.draw(100, 940);
    
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

