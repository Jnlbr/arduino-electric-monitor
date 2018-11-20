#include "Device.h"

Device::Device() {}
Device::Device(int id, String code, String name, bool status, int volt) {
  _id = id;
  _code = code;
  _name = name;
  _status = status;
  _volt = volt;
}
void Device::setId(int id){
  _id = id;
}
int Device::getId() {
  return _id;
}
void Device::setVoltage(int volt){
  _volt = volt;
}
int Device::getVoltage() {
  return _volt;
}
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
void Device::setStatus(bool status) {
  _status = status;
}
bool Device::getStatus() {
  return _status;
}
