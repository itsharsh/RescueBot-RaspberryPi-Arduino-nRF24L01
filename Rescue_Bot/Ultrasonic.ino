void ultrasonic(byte a)
{
  long dist;
  digitalWrite(trigPin[a], LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin[a], HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin[a], LOW);
  dist = pulseIn(echoPin[a], HIGH);
  dist /= 58.2;
  if (dist > 2 && dist < 200)
  {

    distance[a] = (dist * 0.5) + (prevDistance[a] * 0.5);
    prevDistance[a] = distance[a];
  }
}

void printDistance(byte a)
{
  //  Serial.print("Distance ");
  //  Serial.print(a + 1);
  //  Serial.print(": \t");
  Serial.println(distance[a]);
  //  Serial.print("\t");
}

void avoidObstacle()
{
  if (distance[0] == 0 && distance[1] == 0 && distance[2] == 0)
    bot = 1;
  else if (distance[0] < minDistance && distance[1] < minDistance)
    bot = 4;
  else if (distance[2] < minDistance && distance[1] < minDistance)
    bot = 3;
  else if (distance[1] < minDistance)
    bot = 2;
  else if (distance[0] < minDistance)
    bot = 6;
  else if (distance[2] < minDistance)
    bot = 5;
  else
    bot = 1;
}

