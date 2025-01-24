# Line Follower Robot

This project is a simple implementation of a **Line Follower Robot** using an Arduino Uno SMD CH340, motor driver L298N, IR sensors, and other basic components. The robot is designed to follow a black line on a white surface by detecting the line using IR sensors and controlling the motors accordingly.

---

## **Features**
- Detects a black line on a white surface using three forward-facing IR sensors.
- Controls two motors (connected to wheels) for movement.
- Adjusts the movement (forward, left, or right) based on the IR sensor inputs.
- Stops when the line is lost.

---

## **Components Used**

### **Electronics**
- Arduino Uno SMD CH340 (1x)
- L298N Motor Driver Module (1x)
- IR Sensor Modules (3x forward-facing for line detection)
- Motors with gearboxes (2x)
- Wheels for motors (2x)
- Caster wheel (1x)
- Jumper wires (male-to-male and female-to-female)
- Breadboard (optional for testing)
- Resistors (1kΩ, minimum 10x)
- LEDs (minimum 2x)
- Push buttons (minimum 4x)
- Battery for power supply
- Hot glue for assembly

### **Mechanical**
- Robot chassis/body (1x)

---

## **Wiring and Connections**

### **Motors to L298N**
- Motor 1:
  - OUT1 and OUT2 of L298N to the two terminals of Motor 1.
- Motor 2:
  - OUT3 and OUT4 of L298N to the two terminals of Motor 2.

### **IR Sensors to Arduino**
- IR1: Connect signal pin to A0.
- IR2: Connect signal pin to A1.
- IR3: Connect signal pin to A2.

### **Power Connections**
- GND:
  - Connect all GNDs from the IR sensors, motor driver, and Arduino to a common GND.
- VCC:
  - IR sensors: Connect VCC pins to the 5V pin of the Arduino.
  - L298N: Connect the 5V pin of the L298N to the 5V pin of the Arduino.
  - Battery: Connect the positive terminal to the L298N’s 12V pin and the negative terminal to GND.

### **Control Pins (Arduino to L298N)**
- IN1 (Motor 1 control): Digital Pin 1
- IN2 (Motor 1 control): Digital Pin 2
- IN3 (Motor 2 control): Digital Pin 3
- IN4 (Motor 2 control): Digital Pin 4
- ENA (Motor 1 PWM): Digital Pin 9
- ENB (Motor 2 PWM): Digital Pin 10

---

## **Code Overview**

### **Main Logic**
1. IR sensors read the reflected light from the surface:
   - **1 (High):** Black line detected.
   - **0 (Low):** White surface detected.
2. Based on sensor readings:
   - Move forward if the middle sensors detect the line.
   - Turn left or right if the line deviates to one side.
   - Stop if no line is detected.

### **Functions in the Code**
- `forward()`: Moves the robot forward.
- `turnLeft()`: Turns the robot to the left.
- `turnRight()`: Turns the robot to the right.
- `stopMotors()`: Stops both motors.

---

## **How to Upload the Code**
1. Connect the Arduino to your computer using a USB cable.
2. Open the Arduino IDE.
3. Load the provided code into the Arduino IDE.
4. Select the correct board (**Arduino Uno**) and port from the **Tools** menu.
5. Click on **Upload** to transfer the code to the Arduino.
6. Verify successful upload by checking the message in the IDE or observing the serial monitor (optional).

---

## **How to Test the Robot**
1. Place the robot on a surface with a black line on a white background.
2. Power on the robot using the battery.
3. Observe the robot's behavior:
   - It should follow the black line smoothly.
   - It should stop if the line is lost.
4. Use the Serial Monitor in the Arduino IDE to debug sensor readings, if needed.

---

## **Potential Issues and Troubleshooting**
1. **Motors not moving:**
   - Check power connections to the motor driver.
   - Verify PWM signals (ENA and ENB).
2. **Robot not detecting the line:**
   - Check the wiring of IR sensors.
   - Ensure proper placement of IR sensors (close to the surface).
3. **Robot moving erratically:**
   - Verify sensor logic in the code.
   - Ensure all connections are secure.

---

## **Future Improvements**
- Add a PID controller for smoother line following.
- Implement speed adjustment based on curves in the line.
- Use additional sensors for better accuracy.

---

## **Author**
This project was developed as part of a robotics course in the Master's program in Artificial Intelligence and Robotics. Feel free to contribute or suggest improvements!

---

