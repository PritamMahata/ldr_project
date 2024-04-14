const int ledPin = 12; 

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  byte brightness;
  if (Serial.available()) {
    brightness = Serial.read();
    analogWrite(ledPin, brightness);
  }
}