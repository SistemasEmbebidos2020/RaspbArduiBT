# RaspbBT
Comunicación bluetooth bidireccional entre sistemas embebidos

## Paso1: Actualizar fecha: Ojo, modificar día y hora y año de ser necesario, el parámetro -05 es la zona hroaria
#### sudo date -s "Mon Aug 01 08:20:00 -05 2022"
## Paso2: Actualizar rasp:
#### sudo apt-get update
## Paso3: Instalar modulo bt
#### sudo apt-get install bluetooth libbluetooth-dev
#### sudo apt-get install bluez
#### sudo python3 -m pip install pybluez
#### sudo apt-get install bluez bluetooth blueman

## Paso4: Si no está iniciado bt:
#### sudo systemctl start bluetooth
## Paso5: Entrar a modo bt:
#### sudo bluetoothctl  
## Paso6: buscar dispositivos cercanos
#### default-agent
#### scan on
### Paso Opcional:  Si sale un error Reiniciar la Raspberry con sudo reboot
##### y repetir desde el paso 5
## Paso7: Para Emparejar con el dispositivo bt
#### pair 99:99:99:99:99
## Paso8: Les solicitará un Pin perteneciendo al bt disponible
### Si su dispositivo tiene contraseña ingresar la que tenga configurado
### puede ser 1234 o 2022 o 1111 o 0000
## Paso9: Para establecer conexion de confianza
#### trust 99:99:99:99:99
## Paso10: ctrl z para salir modo bt
## Paso11: Para conectarse al bt 
#### sudo rfcomm connect hci 99:99:99:99:99:99

## Paso12: ctrl c para salir

# Paso13: ejecutar código respectivo en raspberry
