int brightness = 0;
const int ledPins[] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
const int numLEDs = 11;
void setup()
{
  Serial.begin(9600); // for calibration
  // setup all 12 leds
  for (int i = 0; i < numLEDs; i++)
  {
    pinMode(ledPins[i], OUTPUT);
    Serial.println(i);
  }
  // setup LDR sensor
  pinMode(A0, INPUT);
  brightness = analogRead(A0);
}

void loop()
{
  brightness = analogRead(A0);
  Serial.println(brightness);
  delay(500);
  if (brightness > 200)
  {
    off_ani();
  }
  else if (brightness > 100)
  {
    on_ani();
  }
  else
  {
    odd_even();
  }
}

void off_ani()
{
  Serial.print("Inside off_ani()");
  for (int i = 0; i < numLEDs; i++)
  {
    digitalWrite(ledPins[i], LOW);
    delay(500);
  }
}

void on_ani()
{
  Serial.print("Inside on_ani()");
  for (int i = 0; i < numLEDs; i++)
  {
    digitalWrite(ledPins[i], HIGH);
    delay(400);
  }
}

void odd_even()
{
  Serial.print("Inside roy()");
  Serial.print(brightness);
  for (int i = 0; i < numLEDs; i++)
  {
    digitalWrite(ledPins[i], HIGH);
    //i++;
    delay(50);
  }
  for (int i = 0; i < numLEDs; i++)
  {
    digitalWrite(ledPins[i], LOW);
    i++;
    delay(50);
  }
  for (int i = 0; i < numLEDs; i++)
  {
    digitalWrite(ledPins[i], LOW);
    //i++;
    delay(50);
  }
}
