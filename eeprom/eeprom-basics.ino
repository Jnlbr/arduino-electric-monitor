void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

long readLong(int start) {
  long bytes[4];
  for(int i = start; i < start+4; i++) {
    bytes[i] = EEPROM.read(i);    
  }
  return ((bytes[0] << 0) & 0xFF) + ((bytes[1] << 8) & 0xFFFF) + ((bytes[2] << 16) & 0xFFFFFF) + ((bytes[3] << 24) & 0xFFFFFFFF);
}

void writeLong(long id) {
  int longBytes = 4;
  for(int i = 0; i < longBytes; i++) {
    byte b = (id >> 8*i) & 0xFF;
    EEPROM.write(i,b);
  }
}
