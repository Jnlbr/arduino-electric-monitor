/*
  Device.h - Device object type
  Created by Jean Lambert, September 29, 2018.
  Released into the public domain.
*/
#ifndef Device_h
#define Device_h
#include "Arduino.h"

class Device {
  public:
    // Device();
    void setCode(String code);
    String getCode();
    void setName(String name);
    String getName();
    void setDeviceType(int type);
    int getDeviceType();
    void setStatus(bool status);
    bool getStatus();
  private:
    String _code;
    String _name;
    int _deviceType;
    bool _status;
};

#endif
