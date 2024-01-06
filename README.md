# Description:
The 40 Hz Light and Audio Device is a system designed to generate a 40 Hz sine wave audio and pulsating light synchronized with the audio. This device leverages brain wave entrainment, where brain waves adjust their frequency to match external stimuli, resulting in improved memory and concentration levels due to increased gamma wave production. This technical document outlines the components used, operation, and includes schematic, PCB design, and 3-D model representations.

# Parts Used:
STM32F103	32 bit MCU clocked at 72Mhz
MCP4725	I2C based 12-bit DAC
LM4880	Is a dual audio power amplifier 250mW per channel, 8 ohm load, 5V supply

# Operation:
•	STM32F103 server the purpose of an MCU.
•	Potentiometers connected with MCU provides reference for the audio volume and light intensity.
•	Sine wave amplitude is stored in array.
•	Once the volume and intensity are calculated from the ADCs of MCU the corresponding sine amplitude is scaled.
•	One the amplitude scaling is done; the signal values are sent to both MCP4725 DAC via I2C and the LED via PWM.
•	Repeating the above steps in loop produces a 40 Hz audio and pulsating light wave.

# Schematic: 
 
# PCB Design:
      

# 3-D Model:

 

# Learning/ Sills gained:
1.	Microcontroller Programming: Gained expertise in programming microcontrollers, particularly the STM32F103, using languages like C/C++ and utilizing development environments like STM32CubeIDE.
2.	Sensor Integration: Learned how to interface potentiometers with the MCU and read analog signals using analog-to-digital converters (ADCs).
3.	Digital-to-Analog Conversion (DAC): Interfacing MCP4725 I2C-based DAC to convert digital signals from the microcontroller into analog signals to control audio volume.
4.	Amplifier Circuit Design: Working with the LM4880 dual audio power amplifier will gave insights into designing audio amplifier circuits for optimal performance.
5.	I2C Communication Protocol: Learned how to communicate with the MCP4725 DAC via the I2C protocol, understanding the principles of serial communication.
6.	PWM (Pulse Width Modulation): Working with PWM signals to control the intensity of the LED will helped understand PWM principles and its applications.
7.	Signal Processing: Applied concepts of signal processing by generating and manipulating sine waves to achieve audio and light pulsation effects.
8.	Circuit Design and Schematic Representation: Designing the circuit and creating the schematic representation added to the hands-on experience
9.	PCB Design: Translating the schematic into a PCB layout allowed to master the art of designing custom printed circuit boards while considering signal integrity and noise reduction.

# Project Images / Videos:

