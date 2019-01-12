template <typename Tick_t, typename Percentage_t>
class SoftwarePwm
{
public:
    SoftwarePwm() :
      _state(false),
      _lastChange(0),
      _dutyCycleTime(ONE_SECOND / FREQUENCY)
    {
        DDRD = B11000000;
        PORTD = 0x0;
        _currentTime = _lowTime;
        SetDutyCyclePercentage(10);
    }

    void SetDutyCyclePercentage(Percentage_t cycle)
    {
        if (cycle < 95)
        {
            _highTime = (_dutyCycleTime * cycle) / 100;
            _lowTime = _dutyCycleTime - _highTime;
        }
    }

    void Service(Tick_t tickUs)
    {
        Tick_t diff = tickUs - _lastChange;

        if (diff >= _currentTime)
        {
            if (_state)
            {
                _state = false;
                PORTD = B00000000;
                _currentTime = _lowTime;
            }
            else
            {
                _state = true;
                PORTD = B11000000;
                _currentTime = _highTime;
            }

            _lastChange = tickUs;
        }
    }

private:
    enum { ONE_SECOND = 1000000 };
    enum { FREQUENCY = 25000 };

    SoftwarePwm(const SoftwarePwm&) = delete;
    const SoftwarePwm& operator=(const SoftwarePwm&) = delete;
    SoftwarePwm(SoftwarePwm&&) = delete;
    SoftwarePwm& operator=(SoftwarePwm&&) = delete;

    bool _state;
    Tick_t _highTime;
    Tick_t _lowTime;
    Tick_t& _currentTime;
    Tick_t _lastChange;
    const Tick_t _dutyCycleTime;
};


