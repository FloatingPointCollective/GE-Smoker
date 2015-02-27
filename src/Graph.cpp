//
//  Graph.cpp
//  GE_smoker-screen1
//
//  Created by Jack Kalish on 2/25/15.
//
//

#include "Graph.h"

string Graph::UNDEFINED = "undefined";
string Graph::LEFT = "left";
string Graph::RIGHT = "right";

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
            ofSetColor(100);
            
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
            _valueFont.drawString(val, width-labelFontBounds.height-valueFontBounds.width-textPadding, center+valueFontBounds.height/2);
            //draw hor line at center of each value
            
            cnt++;
        }
    }
    
    graphFbo.end();
    
    //loadXML
    xmlData.loadFile(xmlFile);
    xmlData.pushTag("graphData");
}

/*void Graph::drawVertVals(){
    
}*/

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
    int n = xmlData.addTag("pt");
    //push into the new tag
    xmlData.pushTag("pt", xmlData.getNumTags("pt")-1);
    xmlData.addValue("value", data);
    xmlData.addValue("time", ofGetTimestampString());
    
    
    
    //pop back out to top level
    xmlData.popTag();
    if(n>100){
        xmlData.removeTag("pt",0);
    }
    xmlData.popTag();
    
    xmlData.saveFile();
}

void Graph::draw(int x, int y){
    ofSetColor(255);
    //draw graph template
    graphFbo.draw(x,y);
    
    //draw line graph
    ////LEFT
    if(isLeft){
        drawLine(x,y,lineColorLeft, "leftAxis",rangeStartLeft,rangeEndLeft);
    }
    
    ////RIGHT
    if(isRight){
        drawLine(x,y,lineColorRight, "rightAxis",rangeStartRight,rangeEndRight);
    }
}

void Graph::drawLine(int x, int y, ofColor c, string tagName, int rangeMin, int rangeMax){
    //draw right to left...
    ofSetColor(c);
    //loop through xml data
    xmlData.pushTag(tagName);
    ofPolyline line;
    int numPts = xmlData.getNumTags("pt");
    int xPos;
    for(int i=0;i<numPts; i++){
        float v = xmlData.getValue("pt:value", 0, numPts-i-1);
        float mappedY = ofMap(v, rangeMin, rangeMax, 0, height-rangePadding*2);
        xPos = x+width-rangePadding-i*10;
        line.addVertex(xPos, y+height-mappedY-rangePadding);
        
        if(xPos<x+rangePadding){
            //remove the first tag
            xmlData.removeTag("pt",0);
            xmlData.saveFile();
        }
    }
    
    ofSetLineWidth(5);
    line.draw();
    xmlData.popTag();
}

void Graph::clearData(){
    cout<<"clear data"<<endl;
    if(isLeft){
        xmlData.pushTag("leftAxis");
        while(xmlData.getNumTags("pt")){
            xmlData.removeTag("pt");
        }
        xmlData.popTag();
    }
    
    ////RIGHT
    if(isRight){
        xmlData.pushTag("rightAxis");
        while(xmlData.getNumTags("pt")){
            xmlData.removeTag("pt");
        }
        xmlData.popTag();
    }
}

float Graph::getTestData(string side){
    if(side == LEFT)
        return ofRandom(rangeStartLeft, rangeEndLeft);
    else if (side == RIGHT)
        return ofRandom(rangeStartRight, rangeEndRight);
}