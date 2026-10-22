// include the servo library
#include <Servo.h>

// defines constants
#define trigPin 4   // trig pin on sensor
#define echoPin 3   // echo pin on sensor

// create an object of type "Servo" to control a servo
Servo myservo;

void setup()
{
  pinMode(trigPin, );   // sends signal (output) MISSING!
  pinMode(echoPin, );   // recieves signal (input) MISSING!

  // attaches the servo on pin 9 to the servo object
  myservo.attach( );    // MISSING! syntax: myservo.attach(pin);

  Serial.begin(9600);   // starts communication with computer
}

void loop()
{
  float duration, distance;   // declare variables (type float) for later use

  // clear any previous signals first
  digitalWrite(trigPin, );    // trigPin set to LOW
  delay(2);                   // wait for 2 millisecond to ensure previous signal is cleared

  // send a signal through the transmitter
  digitalWrite( , );    // trigPin set to HIGH
  delay(10);            // sends for 10 milliseconds

  // reset signal
  digitalWrite( , );    // trigPin set to LOW

  // reads the pulse on the echo pin
  duration = pulseIn(echoPin, HIGH);

  // convert duration to distance in cm
  // distance = (duration x speed of sound [0.034]) / 2
  // remember multiplication is * in C++
  distance = ;  // MISSING! equation

  // displays the distance on the serial monitor
  Serial.print(distance);
  Serial.println(" cm");

  // servo moves "open" when the distance measured is less than 10 (can be changed)
  if (distance < 10){
    // sets the servo postion to 90 degrees
    myservo.write( );   // MISSING! syntax: myservo.write(degree);
  }

  else {
    myservo.write( );   // MISSING! syntax: myservo.write(degree);
  }
}