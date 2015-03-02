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
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    void startTimer();
    void resetTimer();
    
    ofxFTGLFont fontGE170B, fontGE85B, fontGE54B;
    
    int w, h, startTime;
    float secondsPassed;
    
    ofFbo screenFbo;
    ofImage screenImage;
    
    bool isFullScreen;

    ofColor red, blue, green, orange, purple;
    
    string degreeSymbolUnicode;
    
private:
    int lastTime;
    

};
