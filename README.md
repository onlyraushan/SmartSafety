This project is a Real-Time Object Detection System that utilizes an ESP32 microcontroller with an Ultrasonic Distance Sensor (HC-SR04) to measure distances and send instant alerts to a mobile application. The system enhances safety and responsiveness by providing real-time notifications to users.

Features

Real-Time Distance Monitoring: Continuously measures object distance using the HC-SR04 sensor.

Instant Alerts: Sends notifications to a mobile application via Firebase when objects are detected within a critical range.

Visual & Audio Feedback: Uses an RGB LED and Buzzer for immediate local alerts.

Mobile App Integration: Developed using Android Studio & Kotlin to display real-time data with 99% accuracy.

Cloud Connectivity: Firebase integration ensures seamless data synchronization and accessibility.

Tech Stack

Hardware Components

ESP32 (Wi-Fi-enabled microcontroller)

HC-SR04 Ultrasonic Sensor (for distance measurement)

Buzzer & RGB LED (for alerts)

Software & Tools

Kotlin (for Android app development)

Android Studio (IDE for mobile app)

Firebase (for cloud data storage and real-time notifications)

Arduino IDE (for ESP32 programming)

System Architecture

Distance Measurement: The HC-SR04 sensor sends ultrasonic waves and calculates distance based on the echo time.

ESP32 Processing: The ESP32 processes the distance data and triggers alerts if an object is too close.

Real-Time Alerts:

Sends alerts to the Android app via Firebase

Activates Buzzer and RGB LED for local alerts

Mobile App:

Displays real-time distance data

Sends push notifications when critical distance is breached
