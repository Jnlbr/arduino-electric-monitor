#ifndef Device_h
#define Device_h

#include <Arduino.h>

class Device {
  public:
    Device();
    Device(int id, String name, bool status, int volt);
    void setId(int id);
    int getId();
    void setCode(String code);
    String getCode();
    void setName(String name);
    String getName();
    void setStatus(bool status);
    bool getStatus();
    void setVoltage(int volt);
    int getVoltage();
  private:
    int _volt;
    int _id;
    String _code;
    String _name;
    bool _status;
};

#endif
