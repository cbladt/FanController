#include "TransmitReceive.h"

template <typename T>
class AnalogDigitalConverter :
  public TransmitBase<uint16_t>
{
public:
  AnalogDigitalConverter(T pin) :
    _pin(pin)
  {}

  ~AnalogDigitalConverter() final override = default;

  void Service()
  {
    auto reading = static_cast<uint16_t>(analogRead(_pin));
    Transmit(reading);
  }

private:
  T _pin;
};

