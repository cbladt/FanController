#include <Arduino.h>
#include <stdint.h>

class Relay
{
public:
  Relay(uint8_t pin) :
    _state(LOW),
    _pin(pin)
  {
    pinMode(_pin, OUTPUT);
    Set(LOW);
  }

  void EnsureOn()
  {
    if (!_state)
    {
      Set(HIGH);
    }
  }

  void EnsureOff()
  {
    if (_state)
    {
      Set(LOW);
    }
  }
  
private:
  bool _state;
  uint8_t _pin;

  void Set(bool state)
  {
    _state = state;
    digitalWrite(_pin, state);
  }
};
