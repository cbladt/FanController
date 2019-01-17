#ifndef PLATFORMABSTRACTION_STM32F1XX_DIGITALOUTPUT_H_
#define PLATFORMABSTRACTION_STM32F1XX_DIGITALOUTPUT_H_

#include <PlatformAbstraction/IDigitalOutput.h>
#include "stm32f1xx_hal.h"

namespace PlatformAbstraction
{
namespace Stm32f1xx
{
  template <typename PinPort_t, typename PinBit_t>
  class DigitalOutput :
      public IDigitalOutput<DigitalOutput<PinPort_t, PinBit_t>>
  {
  public:
    DigitalOutput(PinPort_t port, PinBit_t bit) :
      _port(port),
      _bit(bit)
    {}

    ~DigitalOutput() = default;

    void SetHigh()
    {
      HAL_GPIO_WritePin(_port, _bit, GPIO_PIN_SET);
    }

    void SetLow()
    {
      HAL_GPIO_WritePin(_port, _bit, GPIO_PIN_RESET);
    }

    void Toggle()
    {
      HAL_GPIO_WritePin(_port, _bit);
    }

    bool GetState()
    {
      return HAL_GPIO_ReadPin(_port, _bit) == GPIO_PIN_RESET;
    }

  private:
    PinPort_t _port;
    PinBit_t _bit;
  };
}
}

#endif /* PLATFORMABSTRACTION_STM32F1XX_DIGITALOUTPUT_H_ */
