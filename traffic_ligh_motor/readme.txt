In this lab you are asked to create a traffic light simulation with a LED, a light sensor and DC
motor. The circuit will start with motor turned on and LED is turned off. The LED will be
turned on randomly, simulating a red light on a traffic stop. When the light sensor detects this
red light (turned on LED), the motor will be turned off. When the LED is turned off again after
a random time interval, the motor will start again. While the circuit is working, you are also asked to print out the randomly selected values for
wait and on time of LED to serial monitor. For this example, the output of light sensor is
assumed to be an integer between 0 and 1000. Depending your light sensor and circuit
construction, these values might be lower or higher.