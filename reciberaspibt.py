import serial, bluetooth
import RPi.GPIO as GPIO
from time import sleep
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM) #puede cambiar a BOARD
led1 = 17  #si cambiar de BCM a Board defina el número del pin acorde a los pines de la raspberry
GPIO.setup(led1, GPIO.OUT)

#cambiar la dirección MAC con la de sus raspberry
celular = "98:D3:63:00:0E:AE"     # HC05 address
port = 1
sock = bluetooth.BluetoothSocket(bluetooth.RFCOMM)

try:
 sock.connect((celular, port))
 sleep(4)   #Espera 4 segundos para conectar bluetooth o puerto
 
 while(1):
  data = ""
  data = sock.recv(1024).decode() 
  print(data)
  if data:
   if   data == 'on1':
    sock.sendall(b"led1 encendido")
    GPIO.output(led1,True)
   elif data == 'off1':
    sock.sendall(b"led1 apagado")
    GPIO.output(led1,False)
 
  
except:
 print("bye  ") 
 sock.close()
 GPIO.cleanup()
