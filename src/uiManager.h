//
//  uiManager.h
//  GE_smoker-screen1
//
//  Created by Jack Kalish on 2/24/15.
//
//

#ifndef __GE_smoker_screen1__uiManager__
#define __GE_smoker_screen1__uiManager__

#include "ofMain.h"
#include "ofxFTGL.h"

#endif /* defined(__GE_smoker_screen1__uiManager__) */

class uiManager{
    public:
    uiManager();
    void setup(int screenNum = 0);
    void update();
    void draw();
    void keyPressed(int key);
    void startTimer();
    void resetTimer();
    
    ofxFTGLFont fontGE170B, fontGE85B, fontGE54B;
    
    int w, h, startTime, _screenNum;
    float secondsPassed, timePassed;
    
    ofFbo screenFbo;
    ofImage screenImage, bgImage;
    
    bool isFullScreen;

    ofColor red, blue, green, orange, purple;
    
    string degreeSymbolUnicode;
    
private:
    int lastTime;
    

};
