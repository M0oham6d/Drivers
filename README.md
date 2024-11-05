# AVR ATmega32 Drivers

This repository contains drivers for the AVR ATmega32 microcontroller, organized into two main layers:

## 1. Microcontroller Abstraction Layer (MCAL)

- **GPIO**: General Purpose Input/Output driver for configuring and controlling the digital I/O pins.
- **ADC**: Analog-to-Digital Converter driver for reading analog signals.
- **Timers**: Timer drivers for handling various timing operations, including delays.
- **UART**: Universal Asynchronous Receiver-Transmitter driver for serial communication.
- **SPI**: Serial Peripheral Interface driver for synchronous serial communication.
- **I2C (TWI)**: Inter-Integrated Circuit driver for multi-master, multi-slave communication.
- **External Interrupts**: Driver for handling external interrupt signals.
- **ICU**: Input Capture Unit driver for capturing and measuring signal timings.
- **PWM**: Pulse Width Modulation driver for generating PWM signals.

## 2. Hardware Abstraction Layer (HAL)

- **LCD**: Driver for interfacing with LCD displays.
- **Keypad**: Driver for reading input from a matrix keypad.
- **EEPROM**: Driver for reading and writing to the EEPROM memory.
- **Ultrasonic Sensor**: Driver for measuring distance using ultrasonic waves.
- **Buzzer**: Driver for controlling a buzzer for sound output.
- **Flame Sensor**: Driver for detecting flame presence.
- **LDR Sensor**: Driver for reading light intensity using a Light Dependent Resistor.
- **LM35 Sensor**: Driver for reading temperature using the LM35 sensor.
- **DC-Motor**: Driver for controlling a DC motor.
- **PIR Sensor**: Driver for detecting motion using a Passive Infrared sensor.
- **Three-LEDs**: Driver for controlling three LEDs.

## Features

- **Modular Design**: Each driver is designed as a separate module for easy integration and maintenance.
- **Documentation**: Comprehensive documentation for each driver, including usage examples.
- **Compatibility**: Designed to be compatible with various development environments and tools.

## Getting Started

1. **Clone the repository**:

    ```bash
    git clone https://github.com/M0oham6d/Drivers.git
    ```

2. **Follow the documentation** in each module’s folder to integrate and use the drivers in your projects.
