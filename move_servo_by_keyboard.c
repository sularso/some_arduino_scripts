// This program demonstrates how to control a servo to move in either direction
// with the keyboard.
//
// Setup:
// - Power (RED) to 5V. Ground (BROWN) to GRD/GRC. Signal (YELLOW) to pin 9.
// - Upload this program to Arduino and connect Servo to board.
// - Download Putty. (http://www.chiark.greenend.org.uk/~sgtatham/putty/)
// 
// Usage:
// - Open putty, connect to the COM port.
// - Input a series of 'e' and press ENTER.
// - Input a series of 'd' (or other char other than 'e') and press ENTER.
// - You should see the servo move in either direction depending if the char
//   is 'e' or non-'e'.

// Ref: http://arduino.cc/en/reference/servo
#include <Servo.h> 
 
Servo servo;
 
int pos = 0;  // Stores the position (angle) of the servo. Range is [0, 180].
 
void setup() 
{ 
  Serial.begin(9600);
  servo.attach(9);  // Attaches the servo on pin 9 to the servo object.
  servo.write(0);  // Resets the position.
} 
 
void loop() 
{
  if (Serial.available()) {  // Returns true if there is serial input.
    char ch = Serial.read();
    
    if (ch == 'e') {
      // Make sure not to exceed the mechanical limitation.
      if (pos < 180) {
        pos += 1;
      }
    } else {
      // Make sure not to exceed the mechanical limitation.
      if (pos > 0) {
        pos -= 1;
      }
    }
    
    // Now ask the servo to move to that position.
    servo.write(pos);
    // Mechnical limitation to the frequency of commands given.
    delay(50);
  }
} 