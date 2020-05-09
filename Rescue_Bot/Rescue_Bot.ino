#include<SPI.h>
#include<RF24.h>
#include "printf.h"
#include <dht.h>

dht DHT;
byte dhtPin = A1;

int CE_PIN = 8, CSN_PIN = 10;
RF24 Radio(CE_PIN, CSN_PIN);
const uint64_t pipeOut = 0xB8B8F0F0E1LL;

struct radio
{
  int left;
  int center;
  int right;
  int temp;
  int humidity;
} data;

byte leftMotor1 = 3;
byte leftMotor2 = 9;
byte rightMotor1 = 5;
byte rightMotor2 = 6;
int throttle = 130, reverse = 130;
int sturn =  0.75 * throttle, hturn = throttle;
byte bot = 1;
//0 Stop
//1 Forward
//2 Reverse
//3 Hard Left
//4 Hard Right
//5 Soft Left
//6 Soft Right

long distance[3], prevDistance[3];
int echoPin[3] = {A5, A3, 2};
int trigPin[3] = {A4, A2, 4};
int minDistance = 8;

void setup()
{
  Serial.begin(9600);
  initRadio();
  for (byte i = 0; i < 3; i++)
  {
    pinMode(trigPin[i], OUTPUT);
    pinMode(echoPin[i], INPUT);
  }
}

void loop()
{
  Serial.println("start");
  DHT.read11(dhtPin);

  for (byte i = 0; i < 3; i++)
  {
    ultrasonic(i);
    printDistance(i);
  }
  if (distance[0] != 0 && distance[1] != 0 && distance[2] != 0)
  {
    avoidObstacle();
    go();
    if (bot == 3 || bot == 4)
      delay(1000);
  }
  Serial.println(DHT.temperature);
  Serial.println(DHT.humidity);

  data.left = distance[0];
  data.center = distance[1];
  data.right = distance[2];
  data.temp = DHT.temperature;
  data.humidity = DHT.humidity;
  Radio.write(&data, sizeof(data));

  Serial.println("stop");
}
