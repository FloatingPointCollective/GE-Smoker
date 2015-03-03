//
//  Dial.h
//  GE_smoker-screen3
//
//  Created by Jack Kalish on 3/2/15.
//
//

#ifndef __GE_smoker_screen3__Dial__
#define __GE_smoker_screen3__Dial__

#include "ofMain.h"
#include "ofxSvg.h"

#endif /* defined(__GE_smoker_screen3__Dial__) */

class Dial{
public:
    Dial();
    void setup();
    void update(float val);
    void draw(int x, int y);
    
private:
    ofxSVG needle;
    float rotation;
};