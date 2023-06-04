/* Membrane
Code for moving parts powered by servo motors
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
long rand1;    // random speed up
long rand2;  // random speed down


int pos = 0;    // variable to store the servo position

void setup() {
  servo1.attach(3);  // attaches the servo on pin 3 to the servo object
  servo2.attach(5);  // attaches the servo on pin 5 to the servo object
  servo3.attach(9);  // attaches the servo on pin 9 to the servo object
  randomSeed(analogRead(0)); //refresh random numbers each loop
}

void loop() {
  rand1 = random(1, 10); //assign random number 
  rand2 = random(1, 10);  // assign random number

  for (pos = 0; pos <= 40; pos += 1) { // goes from 0 degrees to 50 degrees
    // in steps of 1 degree
    servo.write(pos + rand1);              // tell servo to go to position in variable 'pos' + a random number
    servo.write(pos + rand2);              // tell servo to go to position in variable 'pos' + a random number
    servo.write(pos + rand1);              // tell servo to go to position in variable 'pos' + a random number    
    delay(15);                       // waits x ms for the servo to reach the position
  }
  delay(6000);
  for (pos = 40; pos >= 0; pos -= 1) { // goes from 50 degrees to 0 degrees
    servo.write(pos + rand1);              // tell servo to go to position in variable 'pos' + a random number
    servo.write(pos + rand2);              // tell servo to go to position in variable 'pos' + a random number
    servo.write(pos + rand1);              // tell servo to go to position in variable 'pos' + a random number    
    delay(15);                       // waits x ms for the servo to reach the position
  }
  delay(8000);
}
