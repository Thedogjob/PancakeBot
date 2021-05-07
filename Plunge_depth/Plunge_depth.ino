#include <Stepper.h>
  
// change this to the number of steps on your motor
#define STEPS 200

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
Stepper stepper(STEPS,2,3,4,5);
int buttonPin = 26;
int buttonRead = 0;
int pitch = 10; //threads per inch
int ratio = 2/1; //gear2 to gear 1 ratio
int plungeSteps = 0;
int stepCount = 0;
int stepsLeft = 0;
int plunges = 0; //how many times the plunge operation has been called
void setup()
{
  Serial.begin(9600);
  Serial.println("Stepper test!");
  // set the speed of the motor to 30 RPMs
  stepper.setSpeed(35);
  //setup button pin as input
  pinMode(buttonPin,INPUT);
  
  
}

void loop()
{
  buttonRead = 1;
  //buttonRead = digitalRead(buttonPin);
  //Serial.println(buttonRead);
  
  while(buttonRead==1){
    if(plunges==0){
     Serial.println("Input plunge depth (in)"); 
    }
    else{
      Serial.print("Current # of plunges ");
      Serial.println(plunges);
      Serial.println("Input plunge depth (in)"); 
    }
    while(Serial.available()==0){}
      int depth = Serial.parseInt();
      plungeSteps = pitch*depth*ratio*STEPS;
      Serial.println(depth);
      if (depth>0){
        Serial.println("here!");
        while(stepCount < plungeSteps && depth >0){
        Serial.println(stepCount);
        stepCount = stepCount+200;
        stepper.step(STEPS);
        stepsLeft = plungeSteps - stepCount;
        }
        stepper.step(-STEPS*2); //retract plunger to release batter pressure
      }
      else{ 
        Serial.println("going Up!");
        stepsLeft = plungeSteps;
        while(stepCount > plungeSteps && depth <0){
          //Serial.println("Steps to plunge ");
          //Serial.print(stepsLeft);
          //Serial.println("Total Steps ");
          //Serial.print(plungeSteps);
          stepCount = stepCount-200;
          stepper.step(-STEPS);
          stepsLeft = plungeSteps + stepCount; 
        }
      }
      plunges++;
      stepCount = 0;
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
  }
  Serial.println("Goodbye");
}
  
   


// Serial.println("Forward");
   // stepper.step(STEPS);
    //Serial.println("Backward");
    //stepper.step(-STEPS);
