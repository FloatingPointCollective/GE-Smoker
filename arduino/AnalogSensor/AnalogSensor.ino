/*
VernierAnalogSensor (v 2014.09)
Reads a Vernier analog (BTA) Sensor connected to pin A0 of the Arduino. 
This sketch displays the time and sensor readings on the Serial Monitor. 
As written, the readings will be displayed every half second. 
Change the variable TimeBetweenReadings to change the rate.

 See www.vernier.com/arduino for more information.
*/

////////////////////////////////////////
// This is the information on the sensor being used. 
//See the www.vernier.com/products/sensors.
//WIDE RANGE TEMP
float Intercept = -34.46;
float Slope = 72.05;
int TimeBetweenReadings = 500; // in ms
/////////////////////////////////////////
void setup() 
{
  Serial.begin(9600); //initialize serial communication at 9600 baud
}

void loop() 
{
  float Count;
  float Voltage;
  float SensorReading;
  int ReadingNumber=0;
  float Time;
  //the print below does the division first to avoid overflows
  Serial.print(ReadingNumber/1000.0*TimeBetweenReadings); 
  Count = analogRead(A0);
  Voltage = Count / 1023 * 5.0;// convert from count to raw voltage
  SensorReading= Intercept + Voltage * Slope;
  Serial.print("\t"); // tab character
  Serial.println(SensorReading);
  delay(TimeBetweenReadings);// delay in between reads for stability
  ReadingNumber++;
}

