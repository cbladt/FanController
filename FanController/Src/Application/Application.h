#ifndef APPLICATION_APPLICATION_H_
#define APPLICATION_APPLICATION_H_

#include <PlatformAbstraction/Stm32f1xx/DigitalOutput.h>

#include "stm32f1xx_hal.h"
#define PA0_TempASensor_Pin GPIO_PIN_0
#define PA0_TempASensor_GPIO_Port GPIOA
#define PB0_FanAPower_Pin GPIO_PIN_0
#define PB0_FanAPower_GPIO_Port GPIOB
#define PA8_FanASpeed_Pin GPIO_PIN_8
#define PA8_FanASpeed_GPIO_Port GPIOA

namespace Application
{
  void Run();
}

/*public:
  Application()
  {
    using Pin_t = decltype(PB0_FanAPower_Pin);
    using Port_t = decltype(PB0_FanAPower_GPIO_Port);

    PlatformAbstraction::Stm32f1xx::DigitalOutput<Pin_t, Port_t> fanAPower(PB0_FanAPower_Pin, PB0_FanAPower_GPIO_Port);
  }
};*/

#endif /* APPLICATION_APPLICATION_H_ */
