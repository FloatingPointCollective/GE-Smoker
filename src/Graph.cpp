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
}

void Graph::setLeftAxis(string label, ofColor color, int rangeStart, int rangeEnd){
    labelLeft = label;
    lineColorLeft = color;
    rangeStartLeft = rangeStart;
    rangeEndLeft = rangeEnd;
}

void Graph::setRightAxis(string label, ofColor color, int rangeStart, int rangeEnd){
    labelRight = label;
    lineColorRight = color;
    rangeStartRight = rangeStart;
    rangeEndRight = rangeEnd;
}

void Graph::setup(){
    
    int width = 1000;
    int height = 550;
    graphFbo.allocate(width, height);
    
    //draw the graph template to the FBO
    graphFbo.begin();
    //left label, if there is one
    if(labelLeft != UNDEFINED){
        ofRectangle labelFontBounds = _labelFont.getStringBoundingBox(labelLeft, 0, 0);
        _labelFont.drawString(labelLeft, 0, height);
    }
    
    graphFbo.end();
}

void Graph::update(){
    
}

void Graph::draw(int x, int y){
    graphFbo.draw(x,y);
}