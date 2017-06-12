int letterPins[] = {2, 6, 10, 8, 7, 3, 11};
int decimalPin = 9;
int digitPins[] = {12, 5, 4, 1};
int ledPin = 13;

int delayTime = 5000;

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 7; i++)
  {
    pinMode(letterPins[i], OUTPUT);
  }
  pinMode(decimalPin, OUTPUT);
  for (int i = 0; i < 4; i++)
  {
    pinMode(digitPins[i], OUTPUT);
  }
}

boolean start = true;

void loop() {
  digitalWrite(ledPin, LOW);
  if (start)
  {
    timer(1000);
    start = false;
  }
  digitalWrite(ledPin, HIGH);
  number(0, 0, 0, 0, 0);

}

void number(int d1, int d2, int d3, int d4, int dP)
{
  switch (dP)
  {
    case 0:
      digit(1, d4, false);
      digit(2, d3, false);
      digit(3, d2, false);
      digit(4, d1, false);
      break;
    case 1:
      digit(1, d4, true);
      digit(2, d3, false);
      digit(3, d2, false);
      digit(4, d1, false);
      break;
    case 2:
      digit(1, d4, false);
      digit(2, d3, true);
      digit(3, d2, false);
      digit(4, d1, false);
      break;
    case 3:
      digit(1, d4, false);
      digit(2, d3, false);
      digit(3, d2, true);
      digit(4, d1, false);
      break;
    case 4:
      digit(1, d4, false);
      digit(2, d3, false);
      digit(3, d2, false);
      digit(4, d1, true);
      break;
  }
}

void clearAll()
{
  for (int i = 0; i < 7; i++)
  {
    digitalWrite(letterPins[i], LOW);
  }
}

void zero()
{
  for (int i = 0; i < 6; i++)
  {
    digitalWrite(letterPins[i], HIGH);
  }
  digitalWrite(letterPins[6], LOW);
}

void one()
{
  clearAll();
  digitalWrite(letterPins[1], HIGH);
  digitalWrite(letterPins[2], HIGH);
}

void two()
{
  eight();
  digitalWrite(letterPins[2], LOW);
  digitalWrite(letterPins[5], LOW);
}

void three()
{
  eight();
  digitalWrite(letterPins[4], LOW);
  digitalWrite(letterPins[5], LOW);
}

void four()
{
  eight();
  digitalWrite(letterPins[0], LOW);
  digitalWrite(letterPins[3], LOW);
  digitalWrite(letterPins[4], LOW);
}

void five()
{
  eight();
  digitalWrite(letterPins[1], LOW);
  digitalWrite(letterPins[4], LOW);
}

void six()
{
  eight();
  digitalWrite(letterPins[1], LOW);
}

void seven()
{
  clearAll();
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(letterPins[i], HIGH);
  }
}

void eight()
{
  for (int i = 0; i < 7; i++)
  {
    digitalWrite(letterPins[i], HIGH);
  }
}

void nine()
{
  eight();
  digitalWrite(letterPins[4], LOW);
}

void digit(int d, int n, boolean decimal)
{
  if (decimal)
  {
    digitalWrite(decimalPin, HIGH);
  }
  switch (d) {
    case 0: digitalWrite(digitPins[0], LOW);
            digitalWrite(digitPins[1], LOW);
            digitalWrite(digitPins[2], LOW);
            digitalWrite(digitPins[3], LOW);
            break;
    case 1: digitalWrite(digitPins[0], LOW);
            digitalWrite(digitPins[1], HIGH);
            digitalWrite(digitPins[2], HIGH);
            digitalWrite(digitPins[3], HIGH);
            break;
    case 2: digitalWrite(digitPins[0], HIGH);
            digitalWrite(digitPins[1], LOW);
            digitalWrite(digitPins[2], HIGH);
            digitalWrite(digitPins[3], HIGH);
            break;
    case 3: digitalWrite(digitPins[0], HIGH);
            digitalWrite(digitPins[1], HIGH);
            digitalWrite(digitPins[2], LOW);
            digitalWrite(digitPins[3], HIGH);
            break;
    case 4: digitalWrite(digitPins[0], HIGH);
            digitalWrite(digitPins[1], HIGH);
            digitalWrite(digitPins[2], HIGH);
            digitalWrite(digitPins[3], LOW);
            break;
  }

  switch (n) {
    case 0: zero();
            break;
    case 1: one();
            break;
    case 2: two();
            break;
    case 3: three();
            break;
    case 4: four();
            break;
    case 5: five();
            break;
    case 6: six();
            break;
    case 7: seven();
            break;
    case 8: eight();
            break;
    case 9: nine();
            break;
    case 10: clearAll(); // make all them off !
            break;
  }

  delayMicroseconds(delayTime);
  digitalWrite(decimalPin, LOW);
}

void timer(int d)
{
  int d4 = d / 1000;
  int d3 = (d - d4 * 1000) / 100;
  int d2 = (d - d4 * 1000 - d3 * 100) / 10;
  int d1 = d - d4 * 1000 - d3 * 100 - d2 * 10;
  while (d4 != -1)
  {
    while (d3 != -1)
    {
      while (d2 != -1)
      {
        while (d1 != -1)
        {
          int startTime = millis();
          int currentTime = millis();
          while (currentTime - startTime <= 1000)
          {
            number(d4, d3, d2, d1, 0);
            currentTime = millis();
          }
          d1--;
        }

        if (d1 == -1)
        {
          d1 = 9;
        }
        d2--;
      }

      if (d2 == -1)
      {
        d2 = 9;
      }
      d3--;
    }
    if (d3 == -1)
    {
      d3 = 9;
    }
    d4--;
  }

  if (d4 == -1)
  {
    d4 == 0;
  }
}


