void setup() {
  pinMode(8, OUTPUT);
  pinMode(A5, INPUT);
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(A5);

  Serial.print("Pin A5: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > 400)
  {
    tone(8, 1000, 200);
  }
  else
  {
    noTone(8);
  }
  delay(100);
}
