#define TRIG_PIN A1
#define ECHO_PIN A0
#define buzzer 5
#define ledpin 7

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ledpin, OUTPUT);
}

void loop() {
  long duration;
  float distance;

  // Send a 10us HIGH pulse to trigger the sensor
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read echo time
  duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate distance in cm
  distance = duration * 0.034 / 2;

  // Check distance range and control buzzer
  if (distance > 5 && distance < 15) {
    digitalWrite(buzzer, HIGH);  
    digitalWrite(ledpin, HIGH);

    delay(10);
  } else {
    digitalWrite(buzzer, LOW);
    digitalWrite(ledpin, LOW);
  }

  // Print result
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);
}