# Automated Irrigation System for Vegetable Plants

**Location:** Brgy. Union, Mahaplag Elementary School

## Description
An Arduino-based automated irrigation system that waters vegetable plants
when the soil is dry. This repository contains the simulation and source code.

## Online Simulation
Try it here: PASTE-YOUR-WOKWI-LINK-HERE

## How It Works
1. The soil moisture sensor reads the soil (simulated with a potentiometer).
2. If moisture is below 40%, the relay turns the pump ON.
3. If moisture is above 60% (or after 30 seconds), the pump turns OFF.

## Components (Real Build)
- Arduino Uno
- Capacitive soil moisture sensor
- 5V relay module
- 12V water pump and power adapter
- Tubing and jumper wires

## Wiring
| Part | Arduino Pin |
|---|---|
| Sensor SIG | A0 |
| Relay IN | D7 |
| VCC | 5V |
| GND | GND |

## Screenshots
![Circuit](circuit.png)
![Pump ON](pump-on.png)
![Pump OFF](pump-off.png)

## Proponents
- Name 1
- Name 2

## Adviser
- Teacher's name
