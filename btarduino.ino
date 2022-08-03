#include <Arduino.h>
#include <SoftwareSerial.h>   // Incluimos la librería  SoftwareSerial  

SoftwareSerial BT(10,11);    // Definimos los pines RX y TX del Arduino conectados al Bluetooth
String lect;

uint8_t led1 =4;
uint8_t led2 =5;

void setup()
{
  DDRD |= (1<<led1) | (1<<led2);
  BT.begin(9600);       // Inicializamos el puerto serie BT que hemos creado
  Serial.begin(9600);   // Inicializamos  el puerto serie  
  delay(5000);
}
 
void loop()
{
  lect = "";
  if(BT.available()>0)    // Si llega un dato por el puerto BT se envía al monitor serial
  {
    
    lect = BT.readStringUntil('\r');
    Serial.println(lect);
  }
  
  

  if (lect == "on1") {PORTD |= (1<<led1); BT.println("led1 encendido") ;}
  else if (lect == "off1") {PORTD &= ~(1<<led1);  BT.println("led1 apagado") ;}
  else if (lect == "on2") {PORTD |= (1<<led2);  BT.println("led2 encendido") ;}
  else if (lect == "off2") {PORTD &= ~(1<<led2);  BT.println("led2 apagado") ;}
  else if (lect == "offall") { for (int i=4;i<=5;i++) PORTD &= ~(1<<i);  BT.println("leds apagados") ;}
  else if (lect == "onall")  { for (int i=4;i<=5;i++) PORTD |= (1<<i);  BT.println("leds encendidos") ;}
  delay(250);
}
