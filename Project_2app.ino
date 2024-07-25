#include <WiFi.h>
#include <FirebaseESP32.h>

// Firebase configuration
#define FIREBASE_HOST "smart-safety-29fee-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "AIzaSyCKZXAcEIqyc4gvrbkg-Szoq42Auv9Nzs0"

const char* ssid = "xyz";
const char* password = "9708061457";

// Pin definitions
int t = 5;  // Trigger pin for the ultrasonic sensor
int e = 18; // Echo pin for the ultrasonic sensor
int redLed = 15; // Red LED pin
int greenLed = 2; // Green LED pin
int buzzer = 4; // Buzzer pin
float s = 0.034;  // Speed of sound in cm/us
long durn;
float dist_cm;
String ledStatus;
String buzzerStatus;
String ans="";

FirebaseData firebaseData;
FirebaseConfig firebaseConfig;
FirebaseAuth firebaseAuth;

void setup() {
  Serial.begin(115200);
  pinMode(t, OUTPUT);
  pinMode(e, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Set Firebase host and authentication
  firebaseConfig.host = FIREBASE_HOST;
  firebaseConfig.signer.tokens.legacy_token = FIREBASE_AUTH;

  // Initialize Firebase
  Firebase.begin(&firebaseConfig, &firebaseAuth);
  Firebase.reconnectWiFi(true);
}

void loop() {
      digitalWrite(t, LOW);
      delayMicroseconds(2);
      digitalWrite(t, HIGH);
      delayMicroseconds(10);
      digitalWrite(t, LOW);
      durn = pulseIn(e, HIGH);
      dist_cm = durn * s / 2;
      ans=String(dist_cm);
      Serial.println(ans);
      Firebase.setString(firebaseData, "/data", ans);
      Firebase.setBool(firebaseData, "/fireDetected", true);
      // Control LEDs and buzzer based on distance
      if (dist_cm <= 50) {
        digitalWrite(redLed, HIGH);
        digitalWrite(greenLed, LOW);
        digitalWrite(buzzer, HIGH);
        ledStatus = "Red";
        buzzerStatus = "ON";
      } else {
        digitalWrite(redLed, LOW);
        digitalWrite(greenLed, HIGH);
        digitalWrite(buzzer, LOW);
        ledStatus = "Green";
        buzzerStatus = "OFF";
      }
  // Delay before next loop iteration
  delay(1000); // Adjust delay as needed
}
