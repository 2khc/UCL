#include <SD.h>

File tempFile;

void setup()
{
  delay(2000);
  pinMode(P1_1, INPUT);
  pinMode(P2_0, OUTPUT);
  SD.begin(4);
  Serial.begin(9600);
}

void loop()
{
  tempFiles = SD.open("log.txt", FILE_WRITE);
 
  
}

void logTempStats(float temp)
{
   
}

void calcTemp(float termReading)
{
   
}
