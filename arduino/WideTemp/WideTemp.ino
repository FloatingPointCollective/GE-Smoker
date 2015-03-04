/*
CUSTOMIZED BY JACK KALISH FOR 2 SENSOR APPLICATION

VernierThermistor (v 2014.09)
Reads the temperature from a Vernier Stainless Steel Temperature Probe (TMP-BTA)
or Surface Temperature Sensor (STS-BTA) connected to the BTA 1 connector. 
As written, the readings will be displayed every half second. Change the variable 
TimeBetweenReadings to change the rate.

We use the Steinhart-Hart equation (in the function Thermistor) to determine temperature 
from the raw A/D converter reading. Because of the use of log functions, in the Steinhart-Hart 
equation, this sketch requires the math.h library. 

See www.vernier.com/engineering/stem/sensors/temperature-sensor/
for more information on how thermistors are read.

See www.vernier.com/arduino for more information.
 */
#include <math.h>
int ThermistorPIN = 2;// Analog Pin 0
int TimeBetweenReadings = 1000; // in ms
int ReadingNumber=0;

void setup() 
{
  Serial.begin(9600);
}
void loop() 
{
  float Time;
 int Count; //reading from the A/D converter (10-bit)
  float Temp; //the print below does the division first to avoid overflows
 // Serial.print(ReadingNumber/1000.0*TimeBetweenReadings); 
 
  //START
  Serial.print("s");
  
  //ANALOG 1
  Count = analogRead(0);       // read count from the A/D converter 
  Temp = GetTemp(Count);       // and  convert it to CelsiusSerial.print(Time/1000); //display in seconds, not milliseconds                       
  Serial.print(Temp,1);   // display temperature to one digit                                
  Serial.print(":"); //tab character
  
  //ANALOG 2
  Count = analogRead(2);       // read count from the A/D converter 
  Temp = GetTemp(Count);       // and  convert it to CelsiusSerial.print(Time/1000); //display in seconds, not milliseconds                       
  Serial.print(Temp,1);   // display temperature to one digit      
  
  delay(TimeBetweenReadings); // Delay a bit... 
  ReadingNumber++;  
}

float GetTemp(float Count) //This function calculates temperature
{
  float V = Count / 1023 * 5.0;// convert from count to raw voltage
  float Temp;  
  Temp = -33.8 + 73.2*V + .9* (V*V);
  return Temp;                                      // Return the Temperature
}




