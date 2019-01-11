#include "SoftwarePwm.h"
#include <Arduino.h>

SoftwarePwm::SoftwarePwm(uint8_t pin, uint32_t frequency) :
  _pin(pin),
  _frequency(frequency),
  _state(LOW),
  _lastChange(0)
{
  pinMode(_pin, OUTPUT);
  _onePerioed = ONE_SECOND / frequency / 10;
  SetDutyCyclePercentage(30);
}

void SoftwarePwm::SetDutyCyclePercentage(uint8_t dutyCyclePercent)
{
  if (dutyCyclePercent <= 100)
  {
    auto cycle = dutyCyclePercent / 10;
    _highTime = _onePerioed * cycle;
    _lowTime = (_onePerioed * 10) - _highTime;
  }
}

void SoftwarePwm::Service(uint32_t tickUs)
{
  if (tickUs - _lastChange >= (_state ? _highTime : _lowTime))
  {
    ToggleState();
    _lastChange = tickUs;
  }
}

void SoftwarePwm::ToggleState()
{
  if (_state)
  {
    SetState(LOW);
  }
  else
  {
    SetState(HIGH);
  }
}

void SoftwarePwm::SetState(bool state)
{
  _state = state;
  digitalWrite(_pin, state);
}

