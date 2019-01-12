#include <Arduino.h>

template <typename Pin_t>
class DigitalPin
{
public:
  DigitalPin(Pin_t pin) :
    _state(false),
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
  Pin_t _pin;

  void TurnOn()
  {
    _state = true;
    digitalWrite(_pin, true);
  }

  void TurnOff()
  {    
    _state = false;
    digitalWrite(_pin, false);
  }  
};
