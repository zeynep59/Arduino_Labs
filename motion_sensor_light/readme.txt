In this lab you are asked to create a light (represented via a LED) using “HC-SR501
Integrated Motion Sensor” as activation key and using “14 mm Seven Segment Display”
to display remaining time until turning out the light.
Compare this system to motion sensor lights or lamps that you have seen in buildings.
When motion sensor detects a movement, it turns the light on and waits a previously
determined time before it turns the light off and returns to its initial state, waiting for
activation again.
While using “HC-SR501 Integrated Motion Sensor”, you may require to set certain
variables concerning activation distance, location or speed. Try to declare these values as
global variables so that you can change them easily to make it work better.
You can use a single LED to represent light in this experiment. Just turn it on when
motion sensor activated and turn it off when the wait time has passed.
“14 mm Seven Segment Display” is used to show the remaining time until light is turned
off. As you know, it can be used to represent decimal or hexadecimal values. However,
showing larger values may not be possible. Assuming we choose a larger wait time, we
can create a circle animation through “a” to “f” segments, similar to busy mouse pointer
animation in operating systems.