//
//  GraphLine.cpp
//  GE_smoker-screen2
//
//  Created by Jack Kalish on 2/27/15.
//
//

#include "GraphLine.h"

//constructor
GraphLine::GraphLine(){
    
}

void GraphLine::setup(int width, int height, ofColor color, int rangeStart, int rangeEnd, ofxXmlSettings * xml, float res){
    cout<<"line setup color "<<color<<endl;
    _color = color;
    w = width;
    h = height;
    _rangeStart = rangeStart;
    _rangeEnd = rangeEnd;
    _xml = xml;
    _res = res;

}

void GraphLine::draw(int x, int y){
        //draw right to left...
        //loop through xml data
        //xmlData.pushTag(tagName);
        ofPolyline line;
        int numPts = _xml->getNumTags("pt");
        int xPos;
        for(int i=0;i<numPts; i++){
            float v = _xml->getValue("pt:value", 0, numPts-i-1);
            float mappedY = ofMap(v, _rangeStart, _rangeEnd, 0, h);
            xPos = x+w-i*_res;
            line.addVertex(xPos, y+h-mappedY);
            
            if(xPos<x){
                //remove the first tag
                _xml->removeTag("pt",0);
                _xml->saveFile();
            }
        }
    
   // cout<<"drawing line at color "<<_color<<endl;
        ofSetColor(_color);
        ofSetLineWidth(5);
        line.draw();
        //xmlData.popTag();
    
}