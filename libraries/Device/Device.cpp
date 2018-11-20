#include "Device.h"

Device::Device() {}
void Device::setCode(String code) {
  _code = code;
}
String Device::getCode() {
  return _code;
}
void Device::setName(String name) {
  _name = name;
}
String Device::getName() {
  return _name;
}
void Device::setType(int type) {
  _type = type;
}
int Device::getType() {
  return _type;
}
void Device::setStatus(bool status) {
  _status = status;
}
bool Device::getStatus() {
  return _status;
}
