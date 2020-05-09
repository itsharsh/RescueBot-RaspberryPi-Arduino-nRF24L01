void init_radio()
{
  pinMode(radio_LED, OUTPUT);
  Radio.begin();
  printf_begin();
  Radio.setPALevel(RF24_PA_MIN);
  Radio.setDataRate(RF24_250KBPS);
  Radio.openReadingPipe(0, pipeIn);
  Radio.startListening();
  Radio.printDetails();
  delay(2000);
  data.x = 0;
  data.y = 0;
}

void get_radio_data()
{
  if (Radio.available())
  {
    Radio.read(&data, sizeof(data));
    digitalWrite(radio_LED, HIGH);
  }
  else
  {
    digitalWrite(radio_LED, LOW);
  }
}

void print_radio_data()
{
  Serial.print(data.x);
  Serial.print("\t");
  Serial.println(data.y);
}

