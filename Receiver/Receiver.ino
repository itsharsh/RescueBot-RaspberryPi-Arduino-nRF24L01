#include<SPI.h>
#include<RF24.h>
#include "printf.h"

int Left_Motor1 = 3, Left_Motor2 = 5;
int Right_Motor1 = 6, Right_Motor2 = 9;
int forward = 0, reverse = 0, left = 0, right = 0;
int turn_speed = 255, throttle = 255;

int CE_PIN = 8, CSN_PIN = 10;
RF24 Radio(CE_PIN, CSN_PIN);
const uint64_t pipeIn = 0xABCDABCDE1LL;
int radio_LED = 2;

struct Data
{
  int x, y;
} data;

void setup()
{
  Serial.begin(115200);
  pinMode(4, OUTPUT);
  digitalWrite(4, LOW);
  init_radio();
}

void loop()
{
  get_radio_data();
  //  print_radio_data();
  get_speed();
  print_speed();
}


