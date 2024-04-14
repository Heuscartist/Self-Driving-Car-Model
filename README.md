
# Self Driving Car Model

## Introduction
In this project I aim to create a simple model of a self driving car that is capable of following lane markers, avoid collision and detect traffic signs for traffic flow control. The project is made using the following hardware:
- 2WD Robot Chassis
- ESP32 CAM
- Arduino UNO
- IR Sensors x2
- Ultrasonic Sensor

## Project Goals

### Lane Tracking
Lane tracking is to enable the self-driving car to follow lane markers on the road. IR sensors are used to detect the edges of the lane, allowing the car to stay within the lane boundaries. This is crucial for safe and efficient navigation, as it helps the car maintain a steady course and avoid drifting into other lanes or off the road.

![Lane Tracking GIF](LaneFollowing.gif)

### Collision Avoidance
Collision avoidance is a key safety feature that helps the self-driving car detect obstacles in its path and take evasive action to avoid them. The ultrasonic sensor is used to measure the distance to objects in front of the car. If an obstacle is detected too close to the car, it can slow down/stop to prevent a collision.

![Object Avoidance GIF](ObjectAvoidance.gif)

### Object Detection and Edge AI
The ESP32 CAM is equipped with a camera module that enables the self-driving car to detect and recognize traffic signs and signals. This is essential for traffic flow control, as the car can respond appropriately to stop signs, traffic lights, and other road signs. Edge AI refers to the use of artificial intelligence algorithms that run locally on the ESP32 CAM, allowing the car to process and interpret the camera feed in real-time without relying on a remote server. This enables faster and more responsive decision-making, critical for safe navigation in dynamic traffic environments.

![Object Detection GIF](AIObjectDetection.gif)

