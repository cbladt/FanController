#include "TransmitReceive.h"

class Regulator :
  public IReceive<uint16_t>,
  public TransmitBase<uint8_t>
{
public:
  Regulator() = default;
  ~Regulator() final override = default;

  void Receive(uint16_t& temp) final override
  {
    Serial.print("Temperature: ");
    Serial.println(temp);
    auto percentage = GetPercentage(temp);
    Transmit(percentage);
  }

  uint8_t GetPercentage(uint16_t input)
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
