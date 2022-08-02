import serial, bluetooth, time


arduinoHC05 = "98:D3:63:00:0E:AE"     # HC05 address
port = 1
sock = bluetooth.BluetoothSocket(bluetooth.RFCOMM)

data = "m"
try:
 sock.connect((arduinoHC05, port))
 time.sleep(4)   #Espera 4 segundos para conectar bluetooth o puerto
 
 while(1):
  comando = input(
	"""Seleccione entre las siguientes opciones:
                     a = on1
		     b = on2
 	             c = off1
		     d = off2
		     e = onall
 		     f = offall
	su eleccion:.. """)
  if comando:
   if   comando == 'a': sock.sendall(b"on1")
   elif comando == 'b': sock.sendall(b"on2")
   elif comando == 'c': sock.sendall(b"off1")
   elif comando == 'd': sock.sendall(b"off2")
   elif comando == 'f': sock.sendall(b"offall")
   elif comando == 'e': sock.sendall(b"onall")
  
   time.sleep(3)
   data = ""
   data = sock.recv(1024).decode() 
   print(data)
  
except:
 print("bye  ") 
 sock.close()

