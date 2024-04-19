#include <EEPROM.h>
const int ledPins[] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12,13}; 
const int numLEDs = 11;

int main_bright = 0;
int low_bright = 0;
int mid_bright = 0;
int high_bright = 0;
int cur_bright = 0;

const int btnPin = 2;
int btnState = 2;

void setup()
{
  // setup LDR sensor
  pinMode(A0, INPUT);

  // initialize the pushbutton pin as an input:
  pinMode(btnPin, INPUT);

  for (int i = 0; i < numLEDs; i++)
  {
    pinMode(ledPins[i], OUTPUT);
  }
  Serial.begin(9600); // for calibration

  main_bright = readData();

  // calculate calibrated brightness
  low_bright = main_bright * 0.2;
  mid_bright = main_bright * 0.5;
  high_bright = main_bright;
  Serial.println("Turing on the device....");
}

void loop() {
  cur_bright = analogRead(A0);
  Serial.println(cur_bright);
  delay(50);
  btnState = digitalRead(btnPin);
  if (btnState == 0) {
    reCalibrate();
  }
  else {
    checkIntensity();
  }
}

void checkIntensity() {
  if (cur_bright < low_bright) {
    Serial.println("Light intensity lower than 20%");
    on_ani();
    delay(50);
  }
  else if (cur_bright > low_bright && cur_bright < mid_bright) {
    Serial.println("Light intensity between 20% and 50%");
    odd_even();
    delay(50);
  }
  else if (cur_bright > mid_bright && cur_bright < high_bright) {
    Serial.println("Light intensity between 50% and 100%");
    mid_Bright();
    delay(50);
  }
  else {
    Serial.println("Light intensity higher than 100%");
    off_ani();
    delay(50);
  }
}

void reCalibrate() {
  Serial.println("Re-calibrating...");
  delay(30);
  cal();

  // calculate calibrated brightness
  low_bright = main_bright * 0.2;
  mid_bright = main_bright * 0.5;
  high_bright = main_bright;
  Serial.println("Re-calibration Done.....");
  delay(30);
}

void cal() {
  delay(50);

  //reset eeprom data
  for (int i = 0; i < 10; i++) {
    EEPROM.write(i, 0);
  }

  int temp = analogRead(A0);

  // store dinamically
  int i = 0;
  while (temp > 0) {
    if (temp < 255) {
      EEPROM.write(i, temp);
      break;
    }
    else {
      EEPROM.write(i, 255);
      temp -= 255;
    }
    i++;
  }

  main_bright = readData();
}

int readData() {
  int total = 0;
  for (int i = 0; i < 10; i++) {
    total += EEPROM.read(i);
  }
  return total;
}

void off_ani()
{
  for (int i = 0; i < numLEDs; i++)
  {
    digitalWrite(ledPins[i], LOW);
    delay(50);
  }
}

void on_ani()
{
  for (int i = 0; i < numLEDs; i++)
  {
    digitalWrite(ledPins[i], HIGH);
    delay(50);
  }
}

void  odd_even()
{
  for (int i = 0; i < numLEDs; i++)
  {
    digitalWrite(ledPins[i], HIGH);
    i++;
    delay(50);
  }
  for (int i = 1; i < numLEDs; i++)
  {
    digitalWrite(ledPins[i], HIGH);
    i++;
    delay(50);
  }
}

void mid_Bright(){
  digitalWrite(5, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
  
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
}