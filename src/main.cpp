/**
 * I, Ali El Cheikh Ali, student number 000760145, certify that what I am submitting is my own work;
 * that I have not copied it from any other source. I also certify that I have not allowed my work to be copied by others
 */

// library for Arduino framework  
#include <Arduino.h> 
// 1-Wire sensor communication libary 
#include <OneWire.h> 
// DS18B20 sensor library 
#include <DallasTemperature.h> 
 
// Pin that the  DS18B20 is connected to 
const int oneWireBus = D3;      
 
// Setup a oneWire instance to communicate with any OneWire devices 
OneWire oneWire(oneWireBus); 
 
// Pass our oneWire reference to Dallas Temperature sensor  
DallasTemperature DS18B20(&oneWire); 
 
void setup() { 
  // configure the USB serial monitor 
  Serial.begin(115200); 
 
  // Start the DS18B20 sensor 
  DS18B20.begin(); 

  // Checks for sensor address and prints it, else it outputs that its not installed
  uint8_t address[8];
  Serial.println("\nTemprature Application");
  if(DS18B20.getAddress(address, 0))
  {
    Serial.print("Found DS18B20 sensor with address: ");
    for(int i = 0; i<8; i++)
    {
    Serial.print(address[i], HEX);
  
    }
  }
  else
  {
    Serial.println("No DS18B20 temperature sensors are installed!");
  
  }
 
  Serial.println("");

  

} 

 
void loop() { 
  float fTemp; 
  String tempFeeling;
  

  // Makes sure if sensor is connected
  uint8_t address[8];
  if(DS18B20.getAddress(address, 0))
  {

  // ask DS18B20 for the current temperature 
  DS18B20.requestTemperatures(); 
 
  // fetch the temperature.  We only have 1 sensor, so the index is 0. 
  fTemp = DS18B20.getTempCByIndex(0); 
  
  if (fTemp <= 10 ){
      tempFeeling =  "Cold!";
  }

  else if  (fTemp > 10 && fTemp <= 15) {
      tempFeeling =  "Cool";
  }
  else if  (fTemp > 15 && fTemp <= 25) {
      tempFeeling =  "Perfect";
  }
  else if  (fTemp > 25 && fTemp <= 30) {
      tempFeeling =  "Warm";
  }
  else if  (fTemp > 30 && fTemp <= 35) {
      tempFeeling =  "Hot";
  }
  else {
      tempFeeling =  "Too Hot!";
  }
  // print the temp to the USB serial monitor 
  
  Serial.println("Current temperature is: " + String(fTemp) + " deg. Celsius or " + tempFeeling);
  // wait 2s (2000ms) before doing this again 
  delay(5000); 
  }
  

  
}

