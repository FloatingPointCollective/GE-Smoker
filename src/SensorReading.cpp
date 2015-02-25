//
//  SensorReading.cpp
//  GE_smoker
//
//  Created by Jack Kalish on 2/24/15.
//
//

#include "SensorReading.h"

SensorReading::SensorReading(){
    _value = "";
}

void SensorReading::setup(string label, string units, ofColor color, ofxFTGLFont * valueFont, ofxFTGLFont * unitFont, ofxFTGLFont * labelFont)
{
    _label = label;
    _units = units;
    _color = color;
    _valueFont = valueFont;
    _unitFont = unitFont;
    _labelFont = labelFont;
    
    //define vars
    labelHeight = 100;
    padding = 30;
    
    //calculate total height
    height = labelHeight + padding/2 + valueFont->getSize();
}

void SensorReading::update(string value){
    _value = value;
}

void SensorReading::draw(int x, int y){
    //draw label
    ////box
    int labelWidth = 550;

    ofSetColor(_color);
    ofRect(x, y-labelHeight, labelWidth, labelHeight);
    
    ////text
    ofRectangle labelTextBounds = _labelFont->getStringBoundingBox(_label, 0, 0);
    ofSetColor(255);
    _labelFont->drawString(_label, x+labelWidth-labelTextBounds.width-padding, y-labelHeight/2+labelTextBounds.height/2);
    
    int letterSpacing = 30;

    //draw units right-aligned with right edge of label box
    ofSetColor(0);
    ofRectangle valueBounds = _valueFont->getStringBoundingBox(_value, x, y);
    ofRectangle unitBounds = _unitFont->getStringBoundingBox(_units, 0, 0);
    int baseLine = y-labelHeight-padding/2;
    _unitFont->drawString(_units, x+labelWidth-unitBounds.width-padding, baseLine);
    
    //draw value
    _valueFont->drawString(_value, x+labelWidth-unitBounds.width-valueBounds.width-padding-letterSpacing, baseLine);
    
    
    
}