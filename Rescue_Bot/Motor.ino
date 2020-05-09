void go()
{
  switch (bot)
  {
    case 0: Stop(); break;
    case 1: Forward(); break;
    case 2: Reverse(); break;
    case 3: hardLeft(); break;
    case 4: hardRight(); break;
    case 5: softLeft(); break;
    case 6: softRight(); break;
  }
}

void Forward()
{
  motor(throttle, 0, throttle, 0);
  //  Serial.print("Forward");
}
void Reverse()
{
  motor(0, reverse, 0, reverse);
  //  Serial.print("Reverse");
}
void hardLeft()
{
  motor(0, hturn, hturn, 0);
  //  Serial.print("Left");
}
void hardRight()
{
  motor(hturn, 0, 0, hturn);
  //  Serial.print("Right");
}

void softLeft()
{
  motor(throttle, 0, sturn, 0);
  //  Serial.print("Soft Left");
}
void softRight()
{
  motor(sturn, 0, throttle, 0);
  //  Serial.print("Soft Right");
}

void Stop()
{
  motor(0, 0, 0, 0);
  //  Serial.print("Stop");
}

void motor(int a, int b, int c, int d)
{
  analogWrite(leftMotor1, a);
  analogWrite(leftMotor2, b);
  analogWrite(rightMotor1, c);
  analogWrite(rightMotor2, d);
}

