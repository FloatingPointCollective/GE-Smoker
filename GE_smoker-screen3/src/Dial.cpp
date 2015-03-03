//
//  Dial.cpp
//  GE_smoker-screen3
//
//  Created by Jack Kalish on 3/2/15.
//
//

#include "Dial.h"

Dial::Dial(){
    needle.load("needle.svg");
}

void Dial::setup(){
    
}

void Dial::update(float val){
    float clamped = ofClamp(val, 0, 1);
    rotation = 180*clamped;
}

void Dial::draw(int x, int y){
    ofPushMatrix();
    ofTranslate(x, y);
    ofRotate(rotation);
    needle.draw();
    ofPopMatrix();
}