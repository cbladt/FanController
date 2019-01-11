ARDUINO_DIR  = /usr/share/arduino

TARGET       = main
ARDUINO_LIBS =

MCU          = atmega328p
F_CPU        = 16000000

# Avrdude code
ARDUINO_PORT = /dev/ttyACM0
AVRDUDE_ARD_PROGRAMMER = arduino
AVRDUDE_ARD_BAUDRATE = 115200

include ArduinoStuff/Arduino.mk
