// Include NewPing and Servo libraries
#include <NewPing.h>
#include <Servo.h>

// Hook up HC-SR04 with Trig to Arduino Pin 8, Echo to Arduino pin 9
// servo PWM-capable to Arduino pin 10
#define TRIGGER_PIN 8
#define ECHO_PIN 9
#define SERVO_PIN 10

// Maximum distance we want to ping for (in centimeters)
#define MAX_DISTANCE 100	

// NewPing setup of pins and maximum distance
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

// Create a Servo object to control the servo motor
Servo myServo;

// Class to manage a timer
class MoveTimer {
  unsigned long startTime;
  int duration;  // duration in milliseconds
  bool timer_on;

  public:
    MoveTimer(int t) {
      duration = t * 1000;  // convert to milliseconds
      timer_on = false;
    }

    void start_timer() {
      startTime = millis();
      timer_on = true;
    }

    bool check_timer() {
      if (timer_on && (millis() - startTime >= duration)) {
        return true;  // Timer has elapsed
      }
      return false;  // Timer is still running
    }

    void stop_timer() {
      timer_on = false;
    }

    bool is_running() {
      return timer_on;
    }
};

// Create an instance of MoveTimer with a 5-second duration
MoveTimer timer(5);

void setup() {
  Serial.begin(9600);
  myServo.attach(SERVO_PIN);  // Attach the servo to pin 10 (PWM-capable pin)
  myServo.write(0);           // Initialize servo position to 0 degrees
}

void loop() {
  // Measure distance using sonar
  long dist = sonar.ping_cm();
  Serial.print("Distance = ");
  Serial.print(dist);
  Serial.println(" cm");

  // Check if the timer is running and if it has elapsed
  if (timer.is_running()) {
    if (timer.check_timer()) {
      timer.stop_timer();
      myServo.write(90);  // Move servo to 90 degrees
      delay(1000);        // Hold position for 1 second
      myServo.write(0);   // Return servo to 0 degrees
    }
  }

  // Start timer if distance is greater than 15 cm and timer is not running
  if (dist > 15 && !timer.is_running()) {
    timer.start_timer();
  }

  // Stop the timer if the distance is 15 cm or less
  if (dist <= 15 && timer.is_running()) {
    timer.stop_timer();
  }

  delay(500);  // Delay between measurements
}