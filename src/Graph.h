//
//  Graph.h
//  GE_smoker-screen1
//
//  Created by Jack Kalish on 2/25/15.
//
//

#ifndef __GE_smoker_screen1__Graph__
#define __GE_smoker_screen1__Graph__

#include "ofMain.h"
#include "ofxFTGL.h"
#include "ofxXmlSettings.h"

#endif /* defined(__GE_smoker_screen1__Graph__) */

class Graph{
public:
    Graph();
    void setup(string xmlFile);
    void setLeftAxis(string label, ofColor color, int rangeStart, int rangeEnd, int increment);
    void setRightAxis(string label, ofColor color, int rangeStart, int rangeEnd, int increment);
    void update();
    void draw(int x, int y);
    void pushDataToLeftAxis(float data);
    void pushDataToRightAxis(float data);
    void pushData(float data);
    
    ofFbo graphFbo;
    string labelLeft, labelRight;
    ofColor lineColorLeft, lineColorRight;
    int rangeStartLeft, rangeStartRight, rangeEndLeft, rangeEndRight, incrementLeft, incrementRight;
    int rangePadding, width, height;
    
private:
    ofxFTGLFont _labelFont, _valueFont;
    ofxXmlSettings xmlData;
    bool isLeft, isRight;
    
    //statics
    static string UNDEFINED;
    
};