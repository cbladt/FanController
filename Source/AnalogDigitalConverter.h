#include "TransmitReceive.h"
#include <Arduino.h>

template <typename Pin_t, typename Reading_t>
class AnalogDigitalConverter :
  public TransmitBase<Reading_t>
{
public:
  AnalogDigitalConverter(Pin_t pin) :
    _pin(pin)
  {}

  ~AnalogDigitalConverter() final override = default;

  void Service()
  {
    auto reading = static_cast<Reading_t>(analogRead(_pin));
    Transmit(reading);
  }

private:
  Pin_t _pin;
};

