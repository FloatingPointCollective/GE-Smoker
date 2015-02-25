//
//  SensorReading.h
//  GE_smoker
//
//  Created by Jack Kalish on 2/24/15.
//
//

#ifndef __GE_smoker__SensorReading__
#define __GE_smoker__SensorReading__

#include "ofMain.h"
#include "ofxFTGL.h"

#endif /* defined(__GE_smoker__SensorReading__) */

class SensorReading{
    public:
    SensorReading();
    void setup(string label, string units, ofColor color, ofxFTGLFont * valueFont, ofxFTGLFont * unitFont, ofxFTGLFont * labelFont);
    void update(string value);
    void draw(int x, int y);
    ofColor _color;
    string _label, _units, _value;
    ofxFTGLFont * _valueFont, *_unitFont, *_labelFont;
    int height, labelHeight, padding;
    
};