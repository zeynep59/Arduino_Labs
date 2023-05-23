In this lab, you are asked to create an automatic light that activates when the environment
gets dark enough. For this purpose use a LED to represent the light, a light sensor to
detect environment light intensity (e.g. LDR 5mm Light Sensor) and Arduino IDE serial
monitor to print out light sensor value and LED status.
The light sensor might give results ranging from 0 to 800 or 1000. Test your light sensor
to check which values it outputs. When you established possible lowest, highest and
median point (e.g. possibly 400 or 500), you could try to assign median point for light
activation, if the environment light value is higher than this median point, the LED is
turned off and when it is lower, the LED is turned on. You can try to set this median point
slightly lower than current room light density, to make state change easier