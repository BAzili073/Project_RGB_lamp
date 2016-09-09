void readSettings() {
  RED_PERM = EEPROM.read(0);
  GREEN_PERM = EEPROM.read(1);
  BLUE_PERM = EEPROM.read(2);
  mode = EEPROM.read(3);
  // 0 - PERMANENT
  // 10 - RANDOM
  speed_change = EEPROM.read(4);
  freq_random = EEPROM.readInt(5);
  brightness_set = EEPROM.read(7);
}
//EEPROM.write(addr, val);
