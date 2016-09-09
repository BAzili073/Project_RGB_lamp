void serialEvent() {
  while (Serial.available()) {
      char command = (char)Serial.read();
      int argument = Serial.parseInt();
          printDeb("command = ", command);
          printDeb("argument = ", argument);
//      Serial.print("command = ");
//      Serial.println(command);
//      Serial.print("argument = ");
//      Serial.println(argument);
      switch (command) {
        case 'R':
          RED_PERM = (byte)argument;
          EEPROM.write(0, RED_PERM);
          break;
        case 'G':
          GREEN_PERM = (byte)argument;
          EEPROM.write(1, GREEN_PERM);
          break;
        case 'B':
          BLUE_PERM = (byte)argument;
          //EEPROM.write(2, BLUE_PERM);
//          analogWrite(BLUE, argument);
          break;
        case 'm':
          mode = (byte)argument;
          EEPROM.write(3, mode);
          freq_random_counter = 0;
          break;
        case 's':
          speed_change = TIMER_COUNTER / (byte)argument;
          EEPROM.write(4, speed_change);
          speed_change_counter = 0;
          break;
        case 'f':
          freq_random = argument; 
          EEPROM.writeInt(5,freq_random);
          freq_random_counter = 0;
          break;
          
        case 'b':
          brightness_set = (byte)argument;
          EEPROM.write(7, brightness_set);
          
          break;
        default:
          // код для выполнения
          break;
      }
  }
}

void printDeb(char str[], int value) {
  if (DEBUG) {
    Serial.print(str);
    Serial.println(value);
  }
};
