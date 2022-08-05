# RaspbArduiBT
Comunicación bluetooth bidireccional arduino y raspberry 


## Actualizar fecha:
#### sudo date -s "Mon Aug 01 08:20:00 -05 2022"
## Actualizar rasp:
#### sudo apt-get update
## Instalar modulo bt
#### sudo apt-get install bluetooth libbluetooth-dev
#### sudo apt-get install bluez
#### sudo python3 -m pip install pybluez
#### sudo apt-get install bluez bluetooth blueman

## Si no está iniciado bt:
#### sudo systemctl start bluetooth
## Entrar a modo bt:
#### sudo bluetoothctl  
## buscar dispositivos cercanos
#### default-agent
#### scan on
## Para Emparejar con el dispositivo bt
#### pair 99:99:99:99:99
## Para establecer conexion de confianza
#### trust 99:99:99:99:99
## Para conectarse al bt 
#### sudo rfcomm connect hci 99:99:99:99:99:99
## ctrl z para salir modo bt
## ctrl c para salir

# Cargar código arduino y ejecutar código respectivo en raspberry
