# Obstacle Avoidance Robot

An Arduino-based autonomous robot that detects and avoids obstacles using an HC-SR04 ultrasonic sensor, servo motor, and L298N motor driver.

## Features

* Autonomous obstacle detection
* Real-time distance measurement
* Automatic direction scanning
* Collision avoidance
* Servo-controlled ultrasonic sensor

## Hardware Components

* Arduino Uno
* HC-SR04 Ultrasonic Sensor
* SG90 Servo Motor
* L298N Motor Driver
* 2 DC Motors
* Robot Chassis
* Battery Pack

## Pin Connections

| Component    | Arduino Pin |
| ------------ | ----------- |
| HC-SR04 Trig | D2          |
| HC-SR04 Echo | D3          |
| Servo Signal | D4          |
| ENA          | D5          |
| ENB          | D6          |
| IN1          | D8          |
| IN2          | D9          |
| IN3          | D10         |
| IN4          | D11         |

## Working Principle

The robot continuously measures the distance in front of it. When an obstacle is detected, it stops, scans both left and right directions, chooses the path with more free space, and continues moving.

## Author

Ahmed Wahba
