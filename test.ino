int brightness = 0;
const int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
const int numLEDs = 12;

void setup()
{
  // setup all 12 leds
  for (int i = 0; i < numLEDs; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  
  // setup LDR sensor
  pinMode(A0, INPUT);
  brightness = analogRead(A0);
  Serial.begin(9600); // for calibration
}
void loop(){
  brightness = analogRead(A0);
  Serial.println(brightness);
  if (brightness < 150) {
    //digitalWrite(LED_BUILTIN, HIGH);
    //delay(1000);
    for (int i = 0; i < numLEDs; i++) {
       digitalWrite(ledPins[i], HIGH);
     }
  }
  else {
    //digitalWrite(LED_BUILTIN, LOW);
    //delay(1000);
	for (int i = 0; i < numLEDs; i++) {
       digitalWrite(ledPins[i], LOW);
     }
  }
}

int brightness = 0;
const int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
const int numLEDs = 12;
void animate(){
    for (int i = 0; i < numLEDs; i++) {
       digitalWrite(ledPins[i], HIGH);
       delay(200);
       digitalWrite(ledPins[i], LOW);
     }
}
void setup()
{
  // setup all 12 leds
  for (int i = 0; i < numLEDs; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  
  // setup LDR sensor
  pinMode(A0, INPUT);
  brightness = analogRead(A0);
  Serial.begin(9600); // for calibration
  animate();
}
void loop(){
  brightness = analogRead(A0);
  Serial.println(brightness);
  if (brightness < 150) {
    //digitalWrite(LED_BUILTIN, HIGH);
    //delay(1000);
    for (int i = 0; i < numLEDs; i++) {
       digitalWrite(ledPins[i], HIGH);
       delay(200);
     }
  }
  else {
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
  }
}


