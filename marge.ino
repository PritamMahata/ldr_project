#include <EEPROM.h>
//parmanent storage
// const int address1 = 0; //where the data is stored
// const int address2 = 1;

//int val1 = EEPROM.read(address1);
//int val2 = EEPROM.read(address2);
const int ledPins[] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; 
const int numLEDs = 10;

int main_bright = 0;
int low_bright = 0;
int mid_bright = 0;
int high_bright = 0;
int cur_bright = 0;

//add button
const int btnPin = 2;  // the number of the pushbutton pin
int btnState = 2;  // variable for reading the pushbutton status

void setup()
{
  // setup LDR sensor
  pinMode(A0, INPUT);
  for (int i = 0; i < numLEDs; i++)
  {
    pinMode(ledPins[i], OUTPUT);
  }
  Serial.begin(9600); // for calibration

  // initialize the pushbutton pin as an input:
  pinMode(btnPin, INPUT);

  main_bright = readData();

  // calculate calibrated brightness
  low_bright = main_bright * 0.2;
  mid_bright = main_bright * 0.5;
  high_bright = main_bright;
  Serial.println("Turing on the device....");
  delay(500);

  // Serial.print("eeprom value: ");
  // Serial.println(readData());
  // Serial.print("Main bright: ");
  // Serial.println(main_bright);
}

void loop() {
  cur_bright = analogRead(A0);
  Serial.println(cur_bright);
  delay(200);

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
    delay(500);
  }
  else if (cur_bright > low_bright && cur_bright < mid_bright) {
    Serial.println("Light intensity between 20% and 50%");
    odd_even();
    delay(500);
  }
  else if (cur_bright > mid_bright && cur_bright < high_bright) {
    Serial.println("Light intensity between 50% and 100%");
    off_ani();
    delay(500);
  }
  else {
    Serial.println("Light intensity higher than 100%");
    off_ani();
    delay(500);
  }
}

void reCalibrate() {
  Serial.println("Re-calibrating...");
  delay(2000);
  cal();
  // calculate calibrated brightness
  low_bright = main_bright * 0.2;
  mid_bright = main_bright * 0.5;
  high_bright = main_bright;
  Serial.println("Re-calibration Done.....");
  delay(1000);
}

void cal() {
  delay(2000);

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
      // Serial.println(temp);
      break;
    }
    else {
      EEPROM.write(i, 255);
      // Serial.println(temp);
      temp -= 255;
    }
    i++;
  }

  main_bright = readData();
//  Serial.print("main bright: ");
//  Serial.println(main_bright);
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
  for (int i = 0; i < numLEDs; i++)
  {
    digitalWrite(ledPins[i], HIGH);
    i++;
    delay(200);
  }
  for (int i = 1; i < numLEDs; i++)
  {
    digitalWrite(ledPins[i], HIGH);
    i++;
    delay(200);
  }
}