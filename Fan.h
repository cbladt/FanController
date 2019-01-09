#include "SoftwarePwm.h"
#include "Relay.h"
#include "TransmitReceive.h"

class Fan :
  public IReceive<uint8_t>
{
public:
  Fan(uint8_t relayPin, uint8_t pwmPin) :
    _pwm(pwmPin, 25000),
    _relay(relayPin)
  {}

  void Service(uint32_t tickUs)
  {
    _pwm.Service(tickUs);
  }

  void Receive(uint8_t& fanSpeed) final override
  {
    if (fanSpeed > 0)
    {
      _pwm.SetDutyCyclePercentage(fanSpeed);
      _relay.EnsureOn();      
    }
    else
    {
      _relay.EnsureOff();
    }
  }

private:
  SoftwarePwm _pwm;
  Relay _relay;
};
