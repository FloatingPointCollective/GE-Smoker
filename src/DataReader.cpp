//
//  DataReader.cpp
//  GE_smoker
//
//  Created by Jack Kalish on 2/14/15.
//
//

#include "DataReader.h"

void DataReader::setup(string deviceName, int numSensors, string delimiter){
    
    serial.listDevices();
    vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList();
    
    // this should be set to whatever com port your serial device is connected to.
    // (ie, COM4 on a pc, /dev/tty.... on linux, /dev/tty... on a mac)
    // arduino users check in arduino app....
    int baud = 9600;
    //serial.setup(0, baud); //open the first device
    //serial.setup("COM4", baud); // windows example
    setupSuccess = serial.setup(deviceName, baud); // mac osx example
    //serial.setup("/dev/ttyUSB0", baud); //linux example
    
    serialData = "";
    start = false;
    readValueNum = 0;
    _delimiter = delimiter;
    
    for(int i=0; i<=numSensors; i++){
        sensorValues.push_back(0);
    }
}

void DataReader::update(){
    
    if(serial.available()){
        serialData = serial.readByte();
        cout<<serialData;
        
        if(serialData == "s"){
            //found starting point
            start = true;
        }
        
        if(start){
            
            if(serialData == "s"){
                if(valueBeingRead != ""){
                    //store last value
                    sensorValues[readValueNum] = ofToFloat(valueBeingRead);
                }
                readValueNum = 0;
                valueBeingRead = "";
            }
            else if(serialData =="-"){
                //store last value
                sensorValues[readValueNum] = ofToFloat(valueBeingRead);
                //read next value
                readValueNum++;
                valueBeingRead = "";
            }
            else{
                //concat byte to value being read
                valueBeingRead += serialData;
            }
        }
        
    }
    
}

vector<float> DataReader::getSensorValues(){
    
}