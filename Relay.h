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
    TurnOff();
  }

  void EnsureOn()
  {
    if (!_state)
    {
      TurnOn();
    }
  }

  void EnsureOff()
  {
    if (_state)
    {
      TurnOff();
    }
  }
  
private:
  bool _state;
  uint8_t _pin;

  void TurnOn()
  {
    _state = true;
    digitalWrite(_pin, LOW);
  }

  void TurnOff()
  {
    _state = false;
    digitalWrite(_pin, HIGH);
  }  
};
