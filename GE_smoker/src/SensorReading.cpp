//
//  SensorReading.cpp
//  GE_smoker
//
//  Created by Jack Kalish on 2/24/15.
//
//

#include "SensorReading.h"

void SensorReading::setup(string label, string units, ofColor color, ofTrueTypeFont * valueFont, ofTrueTypeFont * unitFont, ofTrueTypeFont * labelFont)
{
    _label = label;
    _units = units;
    _color = color;
}

void SensorReading::update(float value){
    
}

void SensorReading::draw(int x, int y){
    
}