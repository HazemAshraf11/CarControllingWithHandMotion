# CarControllingWithHandMotion
Using two flex sensor connected to a voltage devider circuit connected to two ADC pins of an atmega32 the angle at which each one is bended determines the voltage on the corresponding pin.
The two values are in 10 bits and they are converted to 8 bits to be sent with a master bluetooth module HC-05 connected to another slave HC-05 connected to an atmega32 connected to the car.
The two values determines the direction at which the car is moving
