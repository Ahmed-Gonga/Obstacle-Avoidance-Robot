// Obstacle Avoidance Robot
// Arduino UNO + L298N + HC-SR04 + Servo

#include <Servo.h>

#define ENA 5
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11
#define ENB 6

#define TRIG 2
#define ECHO 3

#define SERVO_PIN 4

Servo myServo;

int speedMotor = 160;

long getDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH);
  long distance = duration * 0.034 / 2;

  return distance;
}

void forward() {
  analogWrite(ENA, speedMotor);
  analogWrite(ENB, speedMotor);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backward() {
  analogWrite(ENA, speedMotor);
  analogWrite(ENB, speedMotor);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left() {
  analogWrite(ENA, speedMotor);
  analogWrite(ENB, speedMotor);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right() {
  analogWrite(ENA, speedMotor);
  analogWrite(ENB, speedMotor);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopRobot() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  myServo.attach(SERVO_PIN);
  myServo.write(90);

  delay(1000);
}

void loop() {
  long distance = getDistance();

  if (distance > 20) {
    forward();
  } 
  else {
    stopRobot();
    delay(300);

    backward();
    delay(400);

    stopRobot();
    delay(300);

    myServo.write(30);
    delay(500);
    long rightDistance = getDistance();

    myServo.write(150);
    delay(500);
    long leftDistance = getDistance();

    myServo.write(90);
    delay(300);

    if (rightDistance > leftDistance) {
      right();
      delay(500);
    } 
    else {
      left();
      delay(500);
    }

    stopRobot();
  }
}
