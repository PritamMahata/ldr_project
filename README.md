# Smart Lamp

This is a software development project that includes a file named `main.ino`. This project is designed to solve [describe the problem this project solves or the functionality it provides]. It is developed using the Arduino platform and is intended to run on [specify the Arduino board model(s)].

## main.ino

`main.ino` is an Arduino sketch file. Arduino sketches are written in C or C++. The `.ino` file is the main part of the Arduino sketch project. This file contains two main functions: `setup()` and `loop()`.

The `setup()` function is called when a sketch starts. This function is used to initialize variables, pin modes, start using libraries, etc. In our `main.ino` file, the `setup()` function [describe what the `setup()` function in your `main.ino` file does].

The `loop()` function is called in a continuous loop after the `setup()` function completes. In our `main.ino` file, the `loop()` function [describe what the `loop()` function in your `main.ino` file does].

## Installation

1. Install the Arduino IDE from the [official Arduino website](https://www.arduino.cc/en/Main/Software).
2. Clone this repository to your local machine.
3. Open the `main.ino` file in the Arduino IDE.

## Usage

1. Connect your Arduino board to your computer.
2. In the Arduino IDE, select the correct board and port from the "Tools" menu.
3. Click the "Upload" button to upload the sketch to your Arduino board.



# Light Intensity Controller

This Arduino project is a light intensity controller that uses an LDR (Light Dependent Resistor) sensor to measure the ambient light intensity and control a series of LEDs accordingly. The LEDs' behavior changes based on the light intensity.

## Features

- Measures ambient light intensity using an LDR sensor.
- Controls a series of 10 LEDs connected to pins 3 through 12.
- The light intensity is categorized into four levels:
  - Lower than 20%
  - Between 20% and 50%
  - Between 50% and 100%
  - Higher than 100%
- Based on the light intensity, the LEDs exhibit different behaviors:
  - If the light intensity is lower than 20%, all LEDs turn on sequentially (`on_ani` function).
  - If the light intensity is between 20% and 50%, the LEDs turn on in an odd-even pattern (`odd_even` function).
  - If the light intensity is between 50% and 100% or higher than 100%, all LEDs turn off sequentially (`off_ani` function).
- A push button connected to pin 2 is used to recalibrate the light intensity levels (`reCalibrate` function).
- The calibrated light intensity levels are stored in the EEPROM for persistent storage across power cycles.

## Setup

- Connect the LDR sensor to analog pin A0.
- Connect the LEDs to digital pins 3 through 12.
- Connect the push button to digital pin 2.

## Usage

Upload the `main.ino` sketch to your Arduino board. The LEDs will start to behave according to the ambient light intensity. Press the push button to recalibrate the light intensity levels.

## Note

This project uses the EEPROM library for storing the calibrated light intensity levels. Please be aware that the EEPROM has a limited write life (usually around 100,000 write cycles). Excessive writing to the EEPROM can wear it out.



## Contributing

We welcome contributions from the community. If you would like to contribute, please follow these steps:

1. Fork the repository.
2. Create a new branch for your features or fixes.
3. Push your changes to your branch.
4. Create a pull request.

Before creating a pull request, please make sure your code follows our coding standards and all tests pass.