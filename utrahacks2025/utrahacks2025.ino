#include <Servo.h>
#include <L298NX2.h>

const int trigPin = 12;
const int echoPin = 13;
const int servoPin = 11;
const int EN1pin = 2;
const int EN2pin = 3;
const int N1pin = 6;
const int N2pin = 9;
const int N3pin = 5;
const int N4pin = 4;
long duration;
int distance;

Servo myServo;
L298NX2 motors(EN1pin, N1pin, N2pin, EN2pin, N3pin, N4pin);

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myServo.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(3);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.println(distance);

  myServo.write(0);
  delay(1000);
  myServo.write(180);
  delay(1000);
  myServo.write(0);
  delay(1000);  

  motors.forwardA();
  delay(1000);
  motors.stopA();
  delay(1000);
  motors.forwardB();
  delay(1000);
  motors.stopB();
  delay(1000);
}

