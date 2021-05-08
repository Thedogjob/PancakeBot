/* Example sketch to control a stepper motor with TB6600 stepper motor driver, AccelStepper library and Arduino: acceleration and deceleration. More info: https://www.makerguides.com */
// Include the AccelStepper library:
#include <AccelStepper.h>
// Define stepper motor connections and motor interface type. Motor interface type must be set to 1 when using a driver:
#define dirPin 2
#define stepPin 3
#define motorInterfaceType 1
// Create a new instance of the AccelStepper class:
AccelStepper stepper = AccelStepper(motorInterfaceType, stepPin, dirPin);

void setup() {
  // Set the maximum speed and acceleration:
  stepper.setMaxSpeed(80);
  stepper.setAcceleration(500);
  stepper.setSpeed(80); 
  Serial.begin(9600); 
  Serial.println ("Press 1 to start");

}

void loop() {
  int goButton = Serial.parseInt();
  if (goButton == 1){
    Serial.println("Input Direction"); 
    int Dir = Serial.parseInt();
    if (Dir ==2); //go 
      Serial.println("We're going down down, in an earlier around!");
      //stepper.runSpeed();
      // Set the target position:
      stepper.moveTo(-80000);
      // Run to target position with set speed and acceleration/deceleration:
      stepper.runToPosition();
      delay(1000);
    if (Dir ==3); //go Up
      Serial.println("Im burning Up!");
      // Move back to zero:
      stepper.moveTo(80000);
      stepper.runToPosition();
      delay(1000);
  }
}
