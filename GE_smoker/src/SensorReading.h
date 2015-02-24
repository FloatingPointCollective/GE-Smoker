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

#endif /* defined(__GE_smoker__SensorReading__) */

class SensorReading{
    public:
    void setup(string label, string units, ofColor color, ofTrueTypeFont * valueFont, ofTrueTypeFont * unitFont, ofTrueTypeFont * labelFont);
    void update(float value);
    void draw(int x, int y);
    ofColor _color;
    string _label, _units;
    ofTrueTypeFont * _valueFont, _unitFont, _labelFont;
    
};