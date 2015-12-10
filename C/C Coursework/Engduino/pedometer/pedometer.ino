// Your Engduino is now a pedometer! It will use the read xyz readings to calculate a magnitude of acceleration
// when it isn't plugged into the computer. When it is plugged in, you can open the Processing Program and press the
// button to upload data from the SD onto your computer.

#include <EngduinoSD.h>
#include <Math.h>;
#include <EngduinoAccelerometer.h>
#include <Wire.h>
#include <EngduinoButton.h>
#include <SPI.h>

void writeToSD(float x, float y, float z);

void setup() 
{
  Serial.begin(9600);
  EngduinoAccelerometer.begin();
  EngduinoButton.begin();
  if (!EngduinoSD.begin())
  {
    Serial.println("SD isn't being recognised... You need one to use this program.");
    while(1){} // hold here if SD broken.
  }
}

void loop() 
{  
  // The Engduino will only store accelerometer data when Serial isn't connected
  // and the SD is recognised as attached.
  if (EngduinoSD.isAttached() && !Serial)
  {   
    float accel[3]; 
    EngduinoAccelerometer.xyz(accel);
    EngduinoSD.open("dataln.txt", FILE_WRITE);
    writeToSD(accel[0],accel[1],accel[2]);
    EngduinoSD.close();
    delay(100);
  }
  
  // When serial port is connected and the Processing program is open, 
  // pressing the button will activate data transfer
  if (EngduinoButton.wasPressed() && Serial)
  {
    EngduinoSD.open("dataln.txt", FILE_READ);    
    while (EngduinoSD.available())    // while there is still data to be read from the file called "dataln.txt"
    {
      Serial.write(EngduinoSD.read());
      delay(1);
    }
     EngduinoSD.close();
     Serial.write('A');                // send an 'A' to processing. This tells processing data transfer is complete.
  }
}

void writeToSD(float x, float y, float z)     
{
  String accel = String(calcAccel(x, y, z));
  EngduinoSD.writeln(accel);                // each acceleration value is written to a new line in the txt file.
}

float calcAccel(float x, float y, float z)  // magnitude of acceleration is calculated in the Engduino
{
  return sqrt(x * x + y * y + z * z);
}

