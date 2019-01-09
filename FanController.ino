#include "AnalogDigitalConverter.h"
#include "NTCTemperature.h"
#include "Regulator.h"
#include "Fan.h"

#define NTC_BETA_COEFFICIENT 3981
#define TEMPERATURE_PIN A7
#define FAN1_PWMPIN 2
#define FAN1_POWERPIN 3

AnalogDigitalConverter<int> adc(TEMPERATURE_PIN);
NTCTemperature temperature(NTC_BETA_COEFFICIENT);
Regulator regulator;
Fan fan1(FAN1_POWERPIN, FAN1_PWMPIN);

void setup() 
{  
  adc.Connect(temperature);
  temperature.Connect(regulator);
  regulator.Connect(fan1);
}

auto last = micros();

void loop() 
{
  auto tick = micros();  
  fan1.Service(tick);    

  if (tick - last > 5000000)
  {
    last = tick;
    adc.Service();
  }
}

