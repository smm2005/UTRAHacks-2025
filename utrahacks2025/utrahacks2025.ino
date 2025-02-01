int trigPin;
int echoPin;
int duration;
int distance;

void setup() {
  trigPin = 10;
  echoPin = 11;
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalRead(trigPin, LOW);
  delayMicroseconds(3);
  digitalRead(trigPin, HIGH);
  delayMicroseconds(10);
  digitalRead(trigPin, LOW);
  delayMicroseconds(3);
  duration = pulseIn(echoPin);
  distance = (duration * 0.034) / 2;
  if (distance <= 10){
    // Incorporate colour detection features
  }
}

