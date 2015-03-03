//
//  GraphLine.h
//  GE_smoker-screen2
//
//  Created by Jack Kalish on 2/27/15.
//
//

#ifndef __GE_smoker_screen2__GraphLine__
#define __GE_smoker_screen2__GraphLine__

#include "ofMain.h"
#include "ofxXmlSettings.h"

#endif /* defined(__GE_smoker_screen2__GraphLine__) */

class GraphLine{
public:
    GraphLine();
    void setup(int width, int height, ofColor color, int rangeStart, int rangeEnd, ofxXmlSettings * xml, float res);
    void draw(int x, int y);
    
    ofColor _color;
    int w, h, _rangeStart, _rangeEnd;
    float _res;
    ofxXmlSettings * _xml;
};