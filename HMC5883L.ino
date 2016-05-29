

#include <Wire.h>
#include <HMC5883L.h>


HMC5883L compass;


void setup()
{
  Serial.begin(9600);

  //initializare  HMC5883L
  while (!compass.begin())
  {
    delay(500);
  }

  // Set measurement range
  compass.setRange(HMC5883L_RANGE_1_3GA);

  // Set measurement mode
  compass.setMeasurementMode(HMC5883L_CONTINOUS);

  // Set data rate
  compass.setDataRate(HMC5883L_DATARATE_30HZ);

  // Set number of samples averaged
  compass.setSamples(HMC5883L_SAMPLES_8);
  
  
}

void loop()
{
  
  Vector mag = compass.readRaw();
  
int prag_X=100;
int prag_Y=-200;
int prag_Z=-50;
  
  int count=0;
  
  delay(1000);
  

  if ((abs(mag.YAxis-prag_Y)>5*abs(prag_Y)) || ((abs(mag.XAxis-prag_X)>5*abs(prag_X))) || ((abs(mag.ZAxis-prag_Z)>5*abs(prag_Z))))
  { 
    Serial.print(mag.XAxis);
    Serial.print(",");
    Serial.print(mag.YAxis);
    Serial.print(",");
    Serial.print(mag.ZAxis);
    Serial.print("\n");  
  }


 else 
 {
  Serial.print("0");
  Serial.print(",");
  Serial.print("0");
  Serial.print(",");
  Serial.print("0");
  Serial.print("\n");
 }
 
   
}
