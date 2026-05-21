# Piezoelectric Energy Harvester

A self-powered piezoelectric energy harvesting system designed to convert ambient mechanical vibrations and footsteps into usable regulated DC power for low-power electronic devices and IoT sensor nodes.

---

## Overview

This project demonstrates the complete pipeline of mechanical-to-electrical energy conversion using piezoelectric sensors, including:

- Piezoelectric energy generation
- AC–DC rectification
- Voltage buffering
- DC–DC buck conversion
- Closed-loop voltage regulation
- Safety monitoring using a window comparator

The system is capable of regulating the harvested energy to a stable **3.3V output** suitable for low-power embedded systems and sensor applications.

---

## Features

- 20-piezoelectric sensor array
- Full-wave bridge rectifier using Schottky diodes
- Op-amp buffer for impedance matching
- PWM-controlled buck converter
- Arduino-based hysteretic (bang-bang) controller
- Window comparator for safe voltage indication
- Real-time over-voltage and under-voltage detection
- Modular architecture for scalability and experimentation

---

## System Architecture

The complete system consists of the following stages:

1. Piezoelectric Sensor Array  
2. AC–DC Rectifier  
3. Buffer Circuit (LM358 Voltage Follower)  
4. Buck Converter  
5. Feedback-Based Buck Controller  
6. Window Comparator Safety Circuit  

---

## Working Principle

### 1. Piezoelectric Energy Generation

Mechanical vibrations or footsteps deform piezoelectric sensors, generating an AC voltage through the direct piezoelectric effect.

The system uses:

- 20 piezoelectric sensors
- 4 sensors connected in series per branch
- 5 such branches connected in parallel

This configuration improves both voltage and current output.

---

### 2. AC–DC Conversion

The generated AC signal is converted to DC using a full-wave bridge rectifier.

Schottky diodes are used to minimize forward voltage loss and improve efficiency at low voltages.

#### Advantages

- Higher efficiency
- Lower ripple
- Better utilization of both AC half cycles
- Improved low-voltage performance

---

### 3. Buffer Stage

Since piezoelectric sources have very high output impedance, an LM358 op-amp configured as a unity-gain voltage follower is used to:

- Prevent loading effects
- Improve energy transfer
- Provide impedance matching
- Isolate the piezo array from the buck converter

The buffer self-powers directly from the harvested energy.

---

### 4. Buck Converter

A PWM-controlled buck converter regulates the varying DC input to a stable **3.3V Output**.

#### Specifications

| Parameter | Value |
|---|---|
| Switching Frequency | 50 kHz |
| Output Voltage | 3.3 V |
| Inductor | 890 µH |
| Capacitor | 5 µF |
| Ripple Target | < 1% |

The converter uses:

- IRLZ44N MOSFET
- LC filter
- Freewheeling diode
- PWM switching control

#### Key Equation

```math
V_{out} = D \times V_{in}
```

Where:

- D = duty cycle
- V<sub>in</sub> = input voltage
- V<sub>out</sub> = regulated output voltage

---

### 5. Controller

The buck converter is controlled using an Arduino Uno implementing a hysteretic bang-bang controller.

#### Control Logic

- Increase duty cycle if output voltage is low
- Decrease duty cycle if output voltage is high
- Maintain duty cycle within a tolerance band

#### Features

- ADC-based voltage sensing
- Dynamic PWM adjustment
- 16-sample averaging for noise reduction
- Under-voltage protection
- Real-time feedback control

This approach provides a simple and robust regulation method suitable for variable piezoelectric energy sources.

---

### 6. Window Comparator

An op-amp based window comparator continuously monitors the regulated output voltage.

#### Voltage Window

| Threshold | Value |
|---|---|
| Lower Threshold | 3.1 V |
| Upper Threshold | 3.5 V |

#### LED Indication

| Condition | LED Status |
|---|---|
| Safe Voltage Range | Blue LED ON |
| Under/Over Voltage | Red LED ON |

This stage provides real-time visual safety indication of system operation.

---

## Results

The hardware implementation successfully demonstrates:

- Stable regulated 3.3V output
- Less than ±1% voltage deviation
- Low ripple voltage
- Successful energy harvesting from mechanical excitation
- Real-time regulation under varying input conditions

---

## Applications

- Self-powered IoT devices
- Wireless sensor nodes
- Smart flooring systems
- Wearable electronics
- Sustainable embedded systems
- Low-power sensing applications
- Energy harvesting research

---

## Components Used

### Piezoelectric Energy Harvesting Stage

- 20 × Piezoelectric Sensors
- Connecting wires
- Soldering materials

### AC–DC Rectifier Stage

- 4 × 1N5819 Schottky Diodes
- Capacitor for output filtering

### Buffer Stage

- LM358 Operational Amplifier
- Supporting resistors and capacitors

### Buck Converter Stage

- IRLZ44N N-Channel MOSFET
- Inductors
- Capacitors
- Freewheeling diode (Schottky Diode)
- Resistors

### Controller Stage

- Arduino Uno
- Voltage divider resistors

### Window Comparator Stage

- LM358 Operational Amplifiers
- Resistor divider network
- Diodes
- Red and Blue LEDs

### Software and Simulation Tools

- LTSpice
- Arduino IDE

### Miscellaneous

- Breadboard
- Jumper wires
- Power supply
- Oscilloscope
- Multimeter

---

## Limitations

- Output power depends heavily on mechanical excitation
- No energy storage element included
- Arduino controller is not a solution for ultra-low-power deployment
- No cold-start optimization
- Diode rectification introduces voltage loss

---

## Future Improvements

- Synchronous rectification
- MPPT (Maximum Power Point Tracking)
- Buck-boost topology
- Supercapacitor or battery integration
- Dedicated low-power controller IC
- Custom PCB implementation
- Improved mechanical coupling

---

## Documentation

Detailed design derivations, LTSpice simulations, theoretical analysis, hardware implementation, and experimental results are available in:

- `Report.pdf`
- `Presentation.pdf`

---

## Contributors

### Nagamalla Sai Abhinav
Electronics and Communication Engineering  
IIIT Hyderabad

### Praveen V
Electronics and Communication Engineering  
IIIT Hyderabad

---


## Repository Structure

```text
Piezoelectric-Energy-Harvester/
│
├── Arduino Code/
│   └── Buck_controller/
│       └── Buck_controller.ino
│
├── Schematics/
│
├── Technology and Symbol Files/
│
├── Presentation.pdf
├── Report.pdf
└── README.md
```

---
