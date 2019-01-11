#include <stdint.h>
#include "TransmitReceive.h"
#include <Arduino.h>

class NTCTemperature :
  public IReceive<uint16_t>,
  public TransmitBase<uint16_t>
{
public:
  NTCTemperature(uint32_t betaCoefficient) :
    _betaCoefficient(betaCoefficient),
    _thermistorNominal(10000),
    _temperatureNominal(25),
    _seriesResistor(10000)
  {}

  ~NTCTemperature() final override = default;

  void Receive(uint16_t& data) final override
  {
    float reading = data;    

    // Calculate resistance.
    reading = 1023 / reading - 1;
    reading = _seriesResistor / reading;    

    // Run Steinhart model.
    float steinhart;
    steinhart = reading / _thermistorNominal;     // (R/Ro)
    steinhart = log(steinhart);                  // ln(R/Ro)
    steinhart /= _betaCoefficient;                   // 1/B * ln(R/Ro)
    steinhart += 1.0 / (_temperatureNominal + 273.15); // + (1/To)
    steinhart = 1.0 / steinhart;                 // Invert
    steinhart -= 273.15;                         // convert to C

    auto temp = static_cast<uint16_t>(steinhart);
    Transmit(temp);
  }
private:  
  uint32_t _betaCoefficient;
  uint32_t _thermistorNominal;
  uint32_t _temperatureNominal;
  uint32_t _seriesResistor;  
};

