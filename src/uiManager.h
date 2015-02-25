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

#endif /* defined(__GE_smoker_screen1__uiManager__) */

class uiManager{
    public:
    uiManager();
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    
    ofTrueTypeFont fontGE170B, fontGE85B, fontGE54B;
    
    int w, h;
    
    ofFbo screenFbo;
    ofImage screenImage;
    
    bool isFullScreen;

    ofColor red, blue, green, orange, purple;

};
