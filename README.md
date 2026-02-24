# Arduino Electromagnet Turns Controller (By Shantanu)

This repository contains the Arduino firmware for controlling stepper motors to wind turns onto an electromagnetic mild steel core. It is designed to work with an **Arduino UNO** and a **CNC Shield V3**.

## Overview
The system synchronously drives two stepper motors (connected to X-axis and Y-axis headers) to rotate the winding mechanism. This ensures even and consistent winding of the coil.

## Hardware Requirements
- Arduino UNO
- CNC Shield V3
- 2x Stepper Motor Drivers (e.g., A4988 or DRV8825)
- 2x Stepper Motors
- Power Supply (12V-24V for stepper drivers)

## Pin Configuration (CNC Shield V3)

The code utilizes the standard pin mapping for limits and steppers on the CNC Shield V3:

| Function | Arduino Pin | Description         |
|----------|-------------|---------------------|
| X_STEP   | 2           | Step pulse for Motor 1 |
| X_DIR    | 5           | Direction for Motor 1  |
| Y_STEP   | 3           | Step pulse for Motor 2 |
| Y_DIR    | 6           | Direction for Motor 2  |
| ENABLE   | 8           | Enable functionality for all drivers (Active LOW) |

## Operation Logic
1. **Initialization**: The code sets the Enable pin LOW to activate the stepper drivers. Both motors are set to the same rotational direction.
2. **Loop**: The `loop()` function generates simultaneous step pulses for both X and Y motors.
   - **Pulse High Time**: 2000 microseconds
   - **Pulse Low Time**: 2000 microseconds
   - **Step Rate**: Approximately 250 steps per second.

## Adjustments
- **Speed**: To change the winding speed, adjust the `delayMicroseconds()` value in the `loop`. Lower values increase speed, while higher values decrease it.
- **Direction**: Toggle `HIGH`/`LOW` on `X_DIR` or `Y_DIR` in `setup()` to change rotation direction.
