#include<SPI.h>
#include<RF24.h>
#include "printf.h"

//NRF      ARDUINO
//1 GND    GND
//2 VCC    3.3V
//3 CE     9  out
//4 CSN    10  out
//5 SCK    13 out
//6 MOSI   11 out
//7 MISO   12 in

int CE_PIN = 9, CSN_PIN = 10;
RF24 Radio(CE_PIN, CSN_PIN);
const uint64_t pipeIn = 0xB8B8F0F0E1LL;

struct radio
{
  int left;
  int center;
  int right;
  int temp;
  int humidity;
} data;

void setup()
{
  Serial.begin(9600);
  Radio.begin();
  printf_begin();
  Radio.setPALevel(RF24_PA_MAX);
  Radio.setDataRate(RF24_2MBPS);
  Radio.setChannel(110);
  Radio.openReadingPipe(0, pipeIn);
  Radio.startListening();
  Radio.printDetails();
  delay(2000);
}

void loop()
{
  if (Radio.available())
  {
    Radio.read(&data, sizeof(data));
    Serial.println("start");
    Serial.println(data.left);
    Serial.println(data.center);
    Serial.println(data.right);
    Serial.println(data.temp);
    Serial.println(data.humidity);
    Serial.println("stop");
  }
}
