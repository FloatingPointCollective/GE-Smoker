//
//  Graph.cpp
//  GE_smoker-screen1
//
//  Created by Jack Kalish on 2/25/15.
//
//

#include "Graph.h"

string Graph::UNDEFINED = "undefined";

//constructor
Graph::Graph(){
    labelLeft = UNDEFINED;
    labelRight = UNDEFINED;
    
    //load fonts
    float fScale = .5;
    _labelFont.loadFont("GEInsBol", 40*fScale);
    _valueFont.loadFont("GEInsBol", 20*fScale);
    
    isLeft = false;
    isRight = false;
}

void Graph::setLeftAxis(string label, ofColor color, int rangeStart, int rangeEnd, int increment){
    labelLeft = label;
    lineColorLeft = color;
    rangeStartLeft = rangeStart;
    rangeEndLeft = rangeEnd;
    incrementLeft = increment;
    isLeft = true;
}

void Graph::setRightAxis(string label, ofColor color, int rangeStart, int rangeEnd, int increment){
    labelRight = label;
    lineColorRight = color;
    rangeStartRight = rangeStart;
    rangeEndRight = rangeEnd;
    incrementRight = increment;
    isRight = true;
}

void Graph::setup(string xmlFile){
    
    width = 1000;
    height = 550;
    int textPadding = 20;
    rangePadding = 100;

    graphFbo.allocate(width, height);
    
    //draw the graph template to the FBO
    graphFbo.begin();
    //left label, if there is one
    ofSetColor(0);
    if(labelLeft != UNDEFINED){
        ofRectangle labelFontBounds = _labelFont.getStringBoundingBox(labelLeft, 0, 0);
        //rotate -90
        ofPushMatrix();
        ofRotate(-90);
        _labelFont.drawString(labelLeft, -height/2-labelFontBounds.width/2, labelFontBounds.height);
        //draw values
        ofPopMatrix();
        
        //draw values
        float spacing = (rangeEndLeft - rangeStartLeft)/incrementLeft;
        int cnt = 0;
        for(int i=rangeStartLeft;i<=rangeEndLeft; i+=incrementLeft){
            string val = ofToString(i);
            ofRectangle valueFontBounds = _valueFont.getStringBoundingBox(val, 0, 0);
            int center = height-((height-rangePadding*2)*(cnt/spacing))-rangePadding;
            ofSetColor(0);
            _valueFont.drawString(val, labelFontBounds.height+textPadding, center+valueFontBounds.height/2);
            //draw hor line at center of each value
            ofSetColor(250);
            
            int left = labelFontBounds.height+valueFontBounds.width+textPadding*2;
            ofRect(left, center, width-left*2, 1);
            cnt++;
        }
    }
    
    //draw X Axis
    ofSetColor(0);
    string xLabel = "Time (hrs)";
    ofRectangle lfb = _labelFont.getStringBoundingBox(xLabel, 0, 0);
    _labelFont.drawString(xLabel, width/2-lfb.width/2, height);
    float range = 5;
    float cnt = 0;
    //go from -5 to 0
    for(int i=-range;i<=0;i++){
        string val = ofToString(i);
        ofRectangle vbb = _valueFont.getStringBoundingBox(val, 0, 0);
        float center = (width-(rangePadding*2))*(cnt/range)+rangePadding;
        _valueFont.drawString(val, center-vbb.width/2, height-lfb.height-textPadding);
        cnt++;
    }
    
    //RIGHT label, if there is one
    if(labelRight != UNDEFINED){
        ofRectangle labelFontBounds = _labelFont.getStringBoundingBox(labelRight, 0, 0);
        //rotate -90
        ofPushMatrix();
        ofRotate(90);
        _labelFont.drawString(labelRight, height/2-labelFontBounds.width/2, -width+labelFontBounds.height);
        //draw values
        ofPopMatrix();
        
        //draw values
        float spacing = (rangeEndRight - rangeStartRight)/incrementRight;
        int cnt = 0;
        for(int i=rangeStartRight;i<=rangeEndRight; i+=incrementRight){
            string val = ofToString(i);
            ofRectangle valueFontBounds = _valueFont.getStringBoundingBox(val, 0, 0);
            int center = height-((height-rangePadding*2)*(cnt/spacing))-rangePadding;
            _valueFont.drawString(val, width-labelFontBounds.height-valueFontBounds.width-textPadding, center-valueFontBounds.height/2);
            //draw hor line at center of each value
            
            cnt++;
        }
    }
    
    graphFbo.end();
    
    //loadXML
    xmlData.loadFile(xmlFile);
    xmlData.pushTag("graphData");
}

void Graph::update(){
    
}

void Graph::pushDataToLeftAxis(float data){

    xmlData.pushTag("leftAxis");
    pushData(data);
}

void Graph::pushDataToRightAxis(float data){
    xmlData.pushTag("rightAxis");
    pushData(data);
}

void Graph::pushData(float data){
    xmlData.addTag("pt");
    xmlData.pushTag("pt");
    xmlData.addValue("value", data);
    xmlData.addValue("time", ofGetTimestampString());
    
    //pop back out to top level
    xmlData.popTag();
    xmlData.popTag();
}

void Graph::draw(int x, int y){
    ofSetColor(255);
    //draw graph template
    graphFbo.draw(x,y);
    
    //draw line graph
    ////LEFT
    if(isLeft){
        //draw right to left...
        ofSetColor(lineColorLeft);
       //loop through xml data
        xmlData.pushTag("leftAxis");
        ofPolyline line;
        for(int i=0;i<xmlData.getNumTags("pt"); i++){
            float v = xmlData.getValue("pt:value", 0, i);
            float mappedY = ofMap(v, rangeStartLeft, rangeEndLeft, 0, height-rangePadding*2);
            line.addVertex(x+width-rangePadding-i*10, y+height-mappedY-rangePadding);
        }
        ofSetLineWidth(5);
        line.draw();
        xmlData.popTag();
    }
    
    ////RIGHT
    if(isRight){
        
    }
}