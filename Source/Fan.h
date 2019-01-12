#include "TransmitReceive.h"

template <typename Percentage_t, typename Relay_t, typename Tick_t, typename Pwm_t>
class Fan :
  public IReceive<Percentage_t>
{
public:  
  Fan(Relay_t& relay, Pwm_t& pwm) :
    _pwm(pwm),
    _relay(relay)
  {}

  void Service(Tick_t tickUs)
  {
    _pwm.Service(tickUs);
  }

  void Receive(Percentage_t& fanSpeed) final override
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
  Pwm_t& _pwm;
  Relay_t& _relay;
};
