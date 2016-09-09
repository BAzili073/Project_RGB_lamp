#include <TimerOne.h>
#include <EEPROMex.h>

#define RED 5
#define GREEN 3
#define BLUE 6
#define PINFORRANDOM A0
#define DEBUG 1
#define MODE_RANDOM 10
#define MODE_PERMANENT 0
#define TIMER_COUNTER 1000

byte brightness_set = 254;
byte brightness_current = 254;
byte mode;
int freq_random = 10; // every value seconds
int t_counter = 0;
byte speed_change = 20; //
byte tim_set;
int speed_change_counter = 0;
int freq_random_counter = 0;
byte RED_SET = 150;
byte GREEN_SET = 150;
byte BLUE_SET = 150;

byte RED_CURRENT = 0;
byte GREEN_CURRENT = 0;
byte BLUE_CURRENT = 0;

byte RED_PERM;
byte GREEN_PERM;
byte BLUE_PERM;

void setup() {
  randomSeed(analogRead(PINFORRANDOM));
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(BLUE,OUTPUT);
  setupTimer(1000);
  Serial.begin(9600);
  readSettings();
  TCCR0B = TCCR0B & 0b11111000 | 0x01;
  TCCR2B = TCCR2B & 0b11111000 | 0x01;
}

void loop() {

}


