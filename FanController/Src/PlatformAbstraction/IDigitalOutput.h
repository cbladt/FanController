#ifndef IDIGITALOUTPUT_H
#define IDIGITALOUTPUT_H

template <typename T>
class IDigitalOutput
{
public:
  virtual ~IDigitalOutput() = default;

  void SetHigh()
  {
    static_cast<T*>(this)->SetHigh();
  }

  void SetLow()
  {
    static_cast<T*>(this)->SetLow();
  }

  void Toggle()
  {
    static_cast<T*>(this)->Toggle();
  }

  bool GetState()
  {
    return static_cast<T*>(this)->GetState();
  }
};

#endif // IDIGITALOUTPUT_H
