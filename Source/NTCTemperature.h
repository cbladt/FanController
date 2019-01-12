#include "TransmitReceive.h"
#include <math.h>

template <typename BetaCoefficient_t, typename Reading_t, typename Temperature_t>
class NTCTemperature :
  public IReceive<Reading_t>,
  public TransmitBase<Temperature_t>
{
public:
  NTCTemperature(BetaCoefficient_t betaCoefficient) :
    _betaCoefficient(betaCoefficient)
  {}

  ~NTCTemperature() final override = default;

  void Receive(Reading_t& data) final override
  {
    float reading = data;    

    // Calculate resistance.
    reading = 1023 / reading - 1;
    reading = SeriesResistor / reading;

    // Run Steinhart model.
    float steinhart;
    steinhart = reading / ThermistorNominal;     // (R/Ro)
    steinhart = log(steinhart);                  // ln(R/Ro)
    steinhart /= _betaCoefficient;                   // 1/B * ln(R/Ro)
    steinhart += 1.0 / (TemperatureNominal + 273.15); // + (1/To)
    steinhart = 1.0 / steinhart;                 // Invert
    steinhart -= 273.15;                         // convert to C

    auto temp = static_cast<Temperature_t>(steinhart);
    Transmit(temp);
  }
private:  
  enum { ThermistorNominal = 10000 };
  enum { TemperatureNominal = 25 };
  enum { SeriesResistor = 10000 };

  BetaCoefficient_t _betaCoefficient;
};

