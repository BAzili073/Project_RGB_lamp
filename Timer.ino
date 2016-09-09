void setupTimer(long msec) {
  Timer1.initialize(msec);
  Timer1.attachInterrupt( timerIsr );
}

void timerIsr()
{
  speed_change_counter++;
  t_counter++;
  if (t_counter == TIMER_COUNTER) { //1 sec
    freq_random_counter++;
    t_counter = 0;
  }

  if ((mode == MODE_PERMANENT) & ((RED_SET != RED_PERM) || (GREEN_SET != GREEN_PERM) || (BLUE_SET != BLUE_PERM))) {
    RED_SET = RED_PERM;
    GREEN_SET = GREEN_PERM;
    BLUE_SET = BLUE_PERM;
  } else if (mode == MODE_RANDOM) { //random
    if (freq_random_counter == freq_random) {
      RED_SET = random(255);
      GREEN_SET = random(255);
      BLUE_SET = random(255);
      freq_random_counter = 0;
    }
  }
  if (speed_change_counter == speed_change) {
    if (RED_CURRENT != RED_SET) RED_CURRENT = changeColor(RED,RED_CURRENT , RED_SET);
    if (GREEN_CURRENT != GREEN_SET) GREEN_CURRENT = changeColor(GREEN, GREEN_CURRENT, GREEN_SET);
    if (BLUE_CURRENT != BLUE_SET) BLUE_CURRENT = changeColor(BLUE, BLUE_CURRENT, BLUE_SET);
    if (brightness_current > brightness_set) brightness_current--;
    if (brightness_current < brightness_set) brightness_current++;
    speed_change_counter = 0;
  }
}

byte changeColor(byte pin, byte current, byte set) {
  if (current > set) {
    current--;
    analogWrite(pin, changeBrightness(current, brightness_current));
  } else if (current < set) {
    current++;
    analogWrite(pin, changeBrightness(current, brightness_current));
  }
  return current;
}

byte changeBrightness(byte current, byte brightness_current ) {
//  Serial.print(brightness_current);
//  Serial.print("&");
//  Serial.print(current);
//  current = map(current, 0, 254, 0, brightness_current);
//  Serial.print("/");
//  Serial.println(current);
  return current;
}

