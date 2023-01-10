#include <Arduino.h>
#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif


BluetoothSerial SerialBT;

String lect;

uint8_t led1 =36;
uint8_t led2 =39;

void setup()
{
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  SerialBT.begin("DarNombre");       // Inicializamos el puerto serie BT que hemos creado
  Serial.begin(9600);   // Inicializamos  el puerto serie  
  delay(5000);
}
 
void loop()
{
  lect = "";
  if(SerialBT.available()>0)    // Si llega un dato por el puerto BT se envía al monitor serial
  {
    
    lect = SerialBT.readStringUntil('\r');
    Serial.println(lect);
  }
  
  

  if (lect == "on1") {digitalWrite(led1,HIGH); SerialBT.println("led1 encendido") ;}
  else if (lect == "off1") {digitalWrite(led1,LOW);  SerialBT.println("led1 apagado") ;}
  else if (lect == "on2") {digitalWrite(led2,HIGH);  SerialBT.println("led2 encendido") ;}
  else if (lect == "off2") {digitalWrite(led2,LOW);  SerialBT.println("led2 apagado") ;}
  else if (lect == "onall") { for (int i=4;i<=5;i++) digitalWrite(i,HIGH);  SerialBT.println("leds encendidos") ;}
  else if (lect == "offall")  { for (int i=4;i<=5;i++) digitalWrite(i,LOW);  SerialBT.println("leds apagados") ;}
  delay(250);
}


#https://gallery.appinventor.mit.edu/?galleryid=97121fe2-ef37-4d52-a4f5-0346e00a29b4
