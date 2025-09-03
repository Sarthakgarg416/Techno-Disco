int soundsensor = 3;
int pirPin = 4;
int led = 9;
int ldrPin = A0;

void setup()
{
  pinMode(soundsensor, INPUT);
  pinMode(pirPin, INPUT);
  pinMode(led, OUTPUT);
}

void loop()
{
  int motion = digitalRead(pirPin);            // PIR sensor: HIGH if motion detected
  int sensorvalue = digitalRead(soundsensor);  // Sound sensor: HIGH if sound detected
  int lightValue = analogRead(ldrPin);         // LDR: 0 (dark) to 1023 (bright)

  if (motion == HIGH && sensorvalue == HIGH)
  {
    int brightness = map(lightValue, 0, 1023, 255, 10);
    brightness = constrain(brightness, 10, 255);
    analogWrite(led, brightness);
  }
  else
  {
    analogWrite(led, 0);  // Turn LED off if no motion or no sound
  }
}