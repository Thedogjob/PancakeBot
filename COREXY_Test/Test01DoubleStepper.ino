#include <Stepper.h>

// change this to the number of steps on your motor
#define miniStep 2 //200 Steps is full rotation
#define oneRotationStep 200 //One Rotation

#define STEPS 200 // The motors take 200 steps per rotation, used for initializing motor set up

// create an instance of the stepper class, specifying
// the number of steps of the motor and the logic pins (5,6,7,8) 
// Make sure the pins are connected sequentially i.e. In1 = 5, In2 = 6, In3 = 7, In4 = 8 
//Or, Gr, Wh, Blu (ascending pin order)
Stepper stepper1(STEPS,8,9,10,11);
Stepper stepper2(STEPS,2,3,4,5); 

//int onOffSwitch = 12;
//int switchStatus = 1;

void setup()
{
  Serial.begin(9600);
  Serial.println("Stepper test!");
  // set the speed of the motor to 80 RPMs
  stepper1.setSpeed(80);
  stepper2.setSpeed(80);
//  pinMode(onOffSwitch,INPUT);

}

void loop(){

  int stepCount = 0;
  
  // Forwards  3 rotations
  while(stepCount < (3*oneRotationStep)){
    stepper1.step(miniStep);
    stepper2.step(-miniStep);
    stepCount = stepCount + miniStep;
    delay(1); // 1 ms delay for computer to not get confused
  }

  // Backwards 3 rotations
  stepCount = 0;
  
  while(stepCount < (3*oneRotationStep)){
    stepper1.step(-miniStep); //run backwards
    stepper2.step(miniStep); //run Backwards
    stepCount = stepCount + miniStep;
    delay(1); // 1 ms delay for computer to not get confused
  }

  //Serial.println("Forward");

}
  
