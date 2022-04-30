# Obstacle-Avoiding-Robot
## Overview:
Obstacle avoidance is an important aspect of mobile robotics. Without it a robot’s
movement in its path would be very restrictive and would lead to some physical damage. This
project proposes a mobile robot that directs itself whenever an obstacle comes in its path. To
build an obstacle avoidance mobile robot we will use ultrasonic sensors for tracking its
movement. An ultrasonic sensor is used to detect any obstacle ahead of it and sends a signal
to the micro controller.

Then the micro controller redirects the robot to move in an alternate
direction by actuating the servo motors which are connected to it through a motor driver.
For hardware our robot vehicle works on Arduino Microcontroller and employs an
ultrasonic distance sensor and a servo motor to detect obstacles. The Arduino acts as the
microcontroller platform and its software part, Arduino Software, was used to carry out the
programming. Our simulation using proteus our model employs three ultrasonic distance
sensors to detect obstacles with GPS module to display its exact location via latitude and
longitude.

## Methodology:
This robotic vehicle uses ultrasonic sensors for its movements. A microcontroller is used to
achieve the desired operation. The motors are connected through the motor driver IC to the
micro controller. Whenever the robot is going on the desired path, the ultrasonic sensor
transmits ultrasonic waves continuously from its sensor head. The ultrasonic sensor also turns

right and left with the servo motor and when the transmitted ultrasonic waves are reflected
from an obstacle and the information is passed to the microcontroller (Arduino UNO) and the
microcontroller calculates the distance on both the sides of the robot. Whichever distance is
less comparatively, the robot is instructed to move on that direction so that it keeps on moving
continuously.

## Components:
1. ARDUINO UNO
2. MOTOR DRIVER
3. HC SR04 ULTRASONIC SENSOR
4. SERVO MOTOR
5. ROBOT CHASIS
6. DC MOTOR WHEELS
7. BREADBOARD
8. GPS module 

### Software simulation [images](https://drive.google.com/drive/folders/1mo8IgG669FtY9zn7pAhIqDfDu0tLcTTz?usp=sharing)

### Hardware simulation [video](https://drive.google.com/file/d/1CJdubmcdzVsobiQJegtEaD21sFlx8z7u/view)
## Conclusion:
Obstacle detection is required by many navigation robots, hence an obstacle avoidance is an important one for a mobile robot. Obstacle Avoidance Robots can be used in a wide range of situations. They can be utilised as service robots to perform home tasks and variety of other interior tasks like vacuum cleaning etc. Obstacle avoidance is an extensively researched and developing technology around the world, and it is certain that most robots will have this capability in the near future.
