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

#endif /* defined(__GE_smoker_screen1__Graph__) */

class Graph{
public:
    Graph();
    void setup();
    void setLeftAxis(string label, ofColor color, int rangeStart, int rangeEnd);
    void setRightAxis(string label, ofColor color, int rangeStart, int rangeEnd);
    void update();
    void draw(int x, int y);
    
    ofFbo graphFbo;
    string labelLeft, labelRight;
    ofColor lineColorLeft, lineColorRight;
    int rangeStartLeft, rangeStartRight, rangeEndLeft, rangeEndRight;
    
private:
    ofxFTGLFont _labelFont, _valueFont;
    
    //statics
    static string UNDEFINED;
    
};