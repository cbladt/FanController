#include "TransmitReceive.h"

template <typename Temperature_t, typename Percentage_t>
class Regulator :
  public IReceive<Temperature_t>,
  public TransmitBase<Percentage_t>
{
public:
  Regulator() = default;
  ~Regulator() final override = default;

  void Receive(Temperature_t& temp) final override
  {    
    auto percentage = GetPercentage(temp);
    Transmit(percentage);
  }

  Percentage_t GetPercentage(Temperature_t& input)
  {
    if (input > 100)
    {
      return 100;
    }

    if (input > 80)
    {
      return 50;
    }

    if (input > 60)
    {
      return 30;
    }

    return 0;
  }
};
