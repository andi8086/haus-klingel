A simple door bell server for ESP32 WROOM-32

Pin 14 - door bell knob signal (active high)
Pin 12 - +3.3V to LED and door bell knob

Pin 12 is set to HIGH upon init. When door bell knob is pressed, it is checked
again after 50 ms for debouncing. If it is still high, the message "dingdong"
is sent as 8 bytes message by UDP broadcast to port 12345 three times during
this repetitions, pin 12 is switched low for 250 ms and back high for 250 ms to
make the LED on the door bell blink as visual feedback.

