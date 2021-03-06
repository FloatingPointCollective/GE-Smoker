//
//  uiManager.cpp
//  GE_smoker-screen1
//
//  Created by Jack Kalish on 2/24/15.
//
//

#include "uiManager.h"

uiManager::uiManager(){
    ofSetVerticalSync(true);
    
    ofBackground(255);
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    //define some vars
    w = 1920;
    h = 1080;
    
    //allocate image objects
    screenFbo.allocate(w, h);
    screenImage.allocate(w, h, OF_IMAGE_COLOR);
    
    //load all fonts to be used
    float fontScale = .5;
    fontGE170B.loadFont("GEInsBol", 170*fontScale);
    fontGE85B.loadFont("GEInsBol", 85*fontScale);
    fontGE54B.loadFont("GEInsBol", 54*fontScale);
    
    //define colors
    red.setHex(0xd1202a);
    blue.setHex(0x0c6bbd);
    green.setHex(0x35aa36);
    orange.setHex(0xef7600);
    purple.setHex(0x4853a0);
    
    isFullScreen = true;
    
    degreeSymbolUnicode = "\u00B0";
    
    lastTime = ofGetElapsedTimeMillis();
    
   // bgImage.loadImage("../../../data/bg.png");
    bgImage.loadImage("bg.png");
    
    _screenNum = 1;
    readingSpacing = 360;
    
    sampleRate = 100;
}

void uiManager::setup(int screenNum){
    _screenNum = screenNum;
}

void uiManager::update(){
    //draw BG
    screenFbo.begin();
    bgImage.drawSubsection(0, 0, w, h, 0, h*(_screenNum-1));
    screenFbo.end();
    
    secondsPassed = (ofGetElapsedTimeMillis() - startTime)/1000;
    timePassed = ofGetElapsedTimeMillis() - startTime;
    
    
}

void uiManager::draw(){
    //don't forget to reset the color to white tho!
    ofSetColor(255);
    
    int newHeight = (ofGetWidth()*h)/w;
    screenFbo.draw(0,0,ofGetWidth(),newHeight);
    //screenImage.draw(0,0);
}

void uiManager::keyPressed(int key){
    switch(key){
        case 'f':
            isFullScreen = ! isFullScreen;
            ofSetFullscreen(isFullScreen);
            break;
    }
}

void uiManager::startTimer(){
    startTime = ofGetElapsedTimeMillis();
}

void uiManager::resetTimer(){
    startTimer();
}

float uiManager::celsiusToFahrenheit(float t){
    return t*9/5+32;
}