#include<SPI.h>
#include<RF24.h>
#include "printf.h"

int new_x = 0, new_y = 0, prev_x = 0, prev_y = 0;

int CE_PIN = 9, CSN_PIN = 10;
RF24 Radio(CE_PIN, CSN_PIN);
const uint64_t pipeOut = 0xABCDABCDE1LL;

struct Data
{
  int x, y;
} data;

void setup()
{
  Serial.begin(115200);
  init_radio();
}

void loop()
{
  new_y = analogRead(A2);
  new_x = analogRead(A3);
  data.x = (prev_x * 0.9) + (new_x * 0.1);
  data.y = (prev_y * 0.9) + (new_y * 0.1);
  Serial.print(data.x);
  Serial.print("\t");
  Serial.println(data.y);
  Radio.write(&data, sizeof(data));
  prev_x = data.x;
  prev_y = data.y;
}
