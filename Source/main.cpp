#include <avr/io.h>
#include <avr/interrupt.h>

#include "DigitalPin.h"
#include "SoftwarePwm.h"
#include "AnalogDigitalConverter.h"
#include "NTCTemperature.h"
#include "Regulator.h"
#include "Fan.h"

#define NTC_BETA_COEFFICIENT 3981
#define TEMPERATURE_PIN A7
#define FAN_POWERPIN 10

using Pin_t = int;
using AnalogReading_t = unsigned short;
using Temperature_t = unsigned short;
using Percentage_t = unsigned char;
using Tick_t = unsigned char;
using Count_t = unsigned char;

AnalogDigitalConverter<Pin_t, AnalogReading_t> adc(TEMPERATURE_PIN);
NTCTemperature<int, AnalogReading_t, Temperature_t> temperature(NTC_BETA_COEFFICIENT);
Regulator<Temperature_t, Percentage_t> regulator;

DigitalPin<Pin_t> relay(FAN_POWERPIN);
SoftwarePwm<Tick_t, Percentage_t> pwm;

Fan<Percentage_t, decltype(relay), Tick_t, decltype(pwm)> fans(relay, pwm);

Tick_t MicroSecondClock = 0;

void SetupTimer()
{
    cli();

    TCCR2A = 0x00;
    TCCR2B = 0x00;
    TCNT2  = 0xFE;
    TIFR2  = 0x00;
    TIMSK2 = 0x00;
    TCCR2B = 0x1;

    sei();
}

int main()
{
    SetupTimer();

    adc.Connect(temperature);
    temperature.Connect(regulator);
    regulator.Connect(fans);

    auto last = MicroSecondClock;
    while (1 == 1)
    {
        if (TCNT2 != MicroSecondClock)
        {
            MicroSecondClock++;
            fans.Service(MicroSecondClock);
        }

        if (MicroSecondClock - last > 5000000)
        {
            last = MicroSecondClock;
            adc.Service();
        }
    }
}
