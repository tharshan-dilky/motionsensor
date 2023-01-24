#include <CayenneMQTTESP8266.h> 
#include <ESP8266WiFi.h> 


char ssid[] = "SSID"; // YOUR SSID


char password[]="PASSWORD"; // YOUR PASSWORD


char username[] = "60dc7050-9bc7-11ed-b193-d9789b2af62b"; // YOURS USERNAME

char mqtt_password[] = "c8069a4e70598cce23df861623d3b3c9d4bf6f0d"; //YOURS mptt_PASSWORD

char client_id[] = "a4f3bed0-9bca-11ed-b193-d9789b2af62b"; // YOURS CLIENT ID


const int PIRpin = D0;// pir pin 


int PIRval = 0;// for reading pir value  



void setup()  

 {  


pinMode(PIRpin,INPUT);//......| Seting sensors and modules input or output 

  

Serial.begin(9600); 

Cayenne.begin(username,mqtt_password,client_id,ssid,password);// starting cayenne  

 

  } 

void loop()  

{  

  Cayenne.loop();  

 

PIRval = digitalRead(PIRpin); // read and store pir value 

Serial.println(PIRval); 

// send sensor values to cayenne 


       Cayenne.virtualWrite(0,PIRval); 



}

