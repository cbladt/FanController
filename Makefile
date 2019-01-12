ARDUINO_DIR  = ArduinoStuff
NO_CORE_MAIN_CPP = True

TARGET       = main
ARDUINO_LIBS =

MCU          = atmega328p
F_CPU        = 16000000

# Avrdude code
ARDUINO_PORT = /dev/ttyUSB1
AVRDUDE_ARD_PROGRAMMER = arduino
AVRDUDE_ARD_BAUDRATE = 115200

include Source/Sources.mk
include ArduinoStuff/Arduino.mk
