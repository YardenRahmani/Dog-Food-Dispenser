# Dog Food Dispenser

**Description:**
An Arduino project that uses an HC-SR04 ultrasonic sensor and SG90 servo motor to automate dog food dispensing. The sensor measures distance and triggers the servo to open a container, dispense food, and then close it. Food is dispensed when a dog is detected continuously in front of the sensor.

## Components
- **Arduino Board**
- **HC-SR04 Ultrasonic Sensor**
- **SG90 Servo Motor**

## Connections
1. **HC-SR04 Ultrasonic Sensor:**
   - **Trig Pin:** Pin 8
   - **Echo Pin:** Pin 9
   - **VCC Pin:** 5V
   - **GND Pin:** GND

2. **SG90 Servo Motor:**
   - **Signal Pin:** Pin 10
   - **VCC Pin:** 5V
   - **GND Pin:** GND

## Setup
1. Connect the HC-SR04 sensor to the Arduino as described above.
2. Connect the SG90 servo motor to the Arduino as described above.
3. Upload the `DogFoodDispenser.ino` sketch to the Arduino using the Arduino IDE.

## Code Overview
- **HC-SR04 Sensor:** Measures distance to detect the presence of a dog.
- **SG90 Servo Motor:** Opens the container to dispense food and then closes it.
- **Dispensing Mechanism:** The servo activates to dispense food when the dog is continuously detected at a distance between 15 cm and 100 cm for a short period.

## Usage
The system will open the container when a dog is detected at the specified distance range for a continuous duration. The container remains open for a set time to dispense food, then closes.

## License
This project is licensed under the MIT License.

## Notes
- Adjust the distance range and servo angles based on your specific setup and container.
- Consider using an external power source for the servo motor to avoid overloading the Arduino.
