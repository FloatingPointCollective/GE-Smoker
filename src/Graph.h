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
#include "GraphLine.h"

#endif /* defined(__GE_smoker_screen1__Graph__) */

class Graph{
public:
    Graph();
    void setup(string xmlFile);
    void setLeftAxis(string label, int rangeStart, int rangeEnd, int increment);
    void setRightAxis(string label, int rangeStart, int rangeEnd, int increment);
    void setBothAxis(string label, int rangeStart, int rangeEnd, int increment);
    void addLine(string axis, ofColor color);
    void update();
    void draw(int x, int y);
    void pushDataToLeftAxis(float data, int which = 0);
    void pushDataToRightAxis(float data, int which = 0);
    void pushData(float data);
    void clearData();
    float getTestData(string side);
    
    ofFbo graphFbo;
    string labelLeft, labelRight;
    int rangeStartLeft, rangeStartRight, rangeEndLeft, rangeEndRight, incrementLeft, incrementRight;
    int rangePadding, width, height;
    float resolution;
    
    static string LEFT, RIGHT;
    
private:
    void drawLine(int x, int y, ofColor c, string tagName, int rangeMin, int rangeMax);
    
    ofxFTGLFont _labelFont, _valueFont;
    ofxXmlSettings xmlData;
    bool isLeft, isRight;
    vector <GraphLine> leftLines, rightLines;
    
    //statics
    static string UNDEFINED;
    
};