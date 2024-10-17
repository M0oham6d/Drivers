AVR ATmega32 Drivers
This repository contains drivers for the AVR ATmega32 microcontroller, organized into two main layers:

1. Microcontroller Abstraction Layer (MCAL)
  GPIO: General Purpose Input/Output driver for configuring and controlling the digital I/O pins.
  ADC: Analog-to-Digital Converter driver for reading analog signals.
  Timers: Timer drivers for handling various timing operations, including delays and PWM generation.
  UART: Universal Asynchronous Receiver-Transmitter driver for serial communication.

3. Hardware Abstraction Layer (HAL)
  LCD: Driver for interfacing with LCD displays.
  Keypad: Driver for reading input from a matrix keypad.
  Sensors: Drivers for various sensors like temperature, distance, etc.

Features:
  Modular Design: Each driver is designed as a separate module for easy integration and maintenance.
  Documentation: Comprehensive documentation for each driver, including usage examples.
  Compatibility: Designed to be compatible with various development environments and tools.
  
Getting Started:
  Clone the repository:
  git clone https://github.com/M0oham6d/Drivers.git

Follow the documentation in each module’s folder to integrate and use the drivers in your projects.
