In this lab you are required to use your DHT11 (or an alternative sensor you have
selected) to get current temperature and humidity in the environment. You are required to
show this info on your LCD screen. Example LCD screen are given below.
While using a push down button, take care to make a change only once while it is
activated (meaning it should only change screen on rising edge of resulting signal), you
should NOT use delay or sleep in this exercise (because they are not necessary), you
should check if the state of button changed from “not pressed” to “pressed” by
remembering previous state at the time of button press event. During button press event,
the screen should only change once.
DHT11 could easily be damaged by not using correct resistance or making faulty
connections. Be careful otherwise, you will require another DHT11 sensor to show your
lab. In this lab, you will be required to show differences in temperature and humidity to
verify your sensor works, be careful not to use fire or other extreme methods to change
sensor values, it could destroy your sensor.
Search if you can get float values for temperature and humidity from DHT11 sensors. If
you are sure that it is not possible to do so and only integer values are returned for both
temperature and humidity, explain it in your code the methods you tried to use to make it
work, how they failed and your explanations and reasoning for why it is not working.