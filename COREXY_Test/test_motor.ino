#include <AccelStepper.h>
#define STEPPER_DIR_PIN 10
#define STEPPER_STEP_PIN 11

AccelStepper stepper(AccelStepper::DRIVER, STEPPER_STEP_PIN,STEPPER_DIR_PIN); 


void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  stepper.setMaxSpeed(1000);
  stepper.setSpeed(50);
}

void loop() {
  // put your main code here, to run repeatedly:
  stepper.runSpeed();
}
