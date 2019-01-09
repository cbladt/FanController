#ifndef TRANSMITRECEIVE_H
#define TRANSMITRECEIVE_H

template <typename T>
class IReceive
{
public:
  virtual void Receive(T& data) = 0;
  virtual ~IReceive() = default;
};

template <typename T>
class TransmitBase
{
public:
  TransmitBase() :
    _receiver(nullptr)
  {}

  virtual ~TransmitBase() = default;

  bool Connect(IReceive<T>& receiver)
  {
    if (_receiver == nullptr)
    {
      _receiver = &receiver;
      return true;
    }

    return false;
  }

  void Transmit(T& data)
  {
    if (_receiver != nullptr)
    {
      _receiver->Receive(data);
    }
  }
private:
  IReceive<T>* _receiver;
};

#endif
