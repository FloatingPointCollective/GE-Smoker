//
//  DataReader.h
//  GE_smoker
//
//  Created by Jack Kalish on 2/14/15.
//
//

#ifndef __GE_smoker__DataReader__
#define __GE_smoker__DataReader__

#include "ofMain.h"

#endif /* defined(__GE_smoker__DataReader__) */

class DataReader{
    
public:
    void setup(string deviceName, int numSensors);
    void update();
    void draw();
    vector<float> getSensorValues();
    
    void gotMessage(ofMessage msg);
    
    ofSerial	serial;
    
    float sensorValue;
    string serialData, valueBeingRead;
    
    bool start;
    int readValueNum;
    
    vector<float> sensorValues;
    
};