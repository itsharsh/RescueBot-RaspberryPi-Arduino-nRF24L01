void get_speed()
{
  if (data.x < 501)
  {
    left = map(data.x, 500, 10, 0, turn_speed);
    right = 0;
    forward = 0;
    reverse = 0;
    Left();
  }
  else if (data.x > 540)
  {
    right = map(data.x, 541, 1023, 0, turn_speed);
    left = 0;
    forward = 0;
    reverse = 0;
    Right();
  }
  else if (data.y < 471)
  {
    reverse = map(data.y, 470, 0, 0, throttle);
    forward = 0;
    left = 0;
    right = 0;
    Reverse();
  }
  else if (data.y > 510)
  {
    forward = map(data.y, 511, 1023, 0, throttle);
    reverse = 0;
    left = 0;
    right = 0;
    Forward();
  }
  else
  {
    forward = 0;
    reverse = 0;
    left = 0;
    right = 0;
    Stop();
  }
}

void print_speed()
{
  Serial.print(forward);
  Serial.print("\t");
  Serial.print(reverse);
  Serial.print("\t");
  Serial.print(left);
  Serial.print("\t");
  Serial.print(right);
  Serial.print("\t");
}

void Forward()
{
  motor(forward, 0, forward, 0);
  Serial.println("Forward");
}
void Reverse()
{
  motor(0, reverse, 0, reverse);
  Serial.println("Reverse");
}
void Left()
{
  motor(0, left, left, 0);
  Serial.println("Left");
}
void Right()
{
  motor(right, 0, 0, right);
  Serial.println("Right");
}
void Stop()
{
  motor(0, 0, 0, 0);
  Serial.println("Stop");
}

void motor(int a, int b, int c, int d)
{
  analogWrite(Left_Motor1, a);
  analogWrite(Left_Motor2, b);
  analogWrite(Right_Motor1, c);
  analogWrite(Right_Motor2, d);
}

