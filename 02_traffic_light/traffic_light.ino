// defines a variable that stores the state of the switch (on or off)
int switchState = 0;

void setup() {
  // pinMode function parameters: pinMode(pin, mode)
  // pin: the arduino pin number the component is connected to
  // mode: input or output device
  pinMode(2, INPUT);    // button
  pinMode( , );         // green LED
  pinMode( , );         // red LED 1
  pinMode( , );         // red LED 2
}

void loop() {
  // checks the button for voltage
  switchState =   // missing: needs a digitalRead(pin) function

  // if the button has not been pressed
  if (switchState == LOW) {
    // digitalWrite function parameters: digitalWrite(pin, value)
    digitalWrite(5, HIGH);    // red LED 1 turns on
    digitalWrite( , );        // red LED 2 turns off
    digitalWrite( , );        // green LED turns off
  }

  else {
    digitalWrite( , );    // red LED 1 turns off
    digitalWrite( , );    // red LED 2 turns on
    delay(500);           // waits half a second

    digitalWrite( , );    // red LED 2 turns off
    digitalWrite( , );    // green LED turns on
    delay(500);
  }

} // goes back to the beginning of the loop