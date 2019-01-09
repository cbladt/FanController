#include <stdint.h>

class SoftwarePwm
{
public:
  SoftwarePwm(uint8_t pin, uint32_t frequency);

  void SetDutyCyclePercentage(uint8_t dutyCycle);

  void Service(uint32_t tickUs);

private:
  enum { ONE_SECOND = 1000000 };  

  SoftwarePwm(const SoftwarePwm&) = delete;
  const SoftwarePwm& operator=(const SoftwarePwm&) = delete;
  SoftwarePwm(SoftwarePwm&&) = delete;
  SoftwarePwm& operator=(SoftwarePwm&&) = delete;

  void ToggleState();
  void SetState(bool state);

  bool _state;
  uint8_t _pin;
  uint32_t _frequency;
  uint32_t _highTime;
  uint32_t _lowTime;
  uint32_t _lastChange;
  public:
  uint32_t _onePerioed;
};


