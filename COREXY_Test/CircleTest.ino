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


//Circle Math Initialization
float t = 0;
float r = 250;
float x_old = 0; //initialized on position when t = 0 which is (1,0)... NOT (0,0)
float y_old = 0;
float x_new = 0;
float y_new = 0;
float dx = 0;
float dy = 0;
float dA = 0;
float dB = 0;

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
  while(Serial.available() ==0) {}
    int start = Serial.parseInt();
     if (start ==1){ 
        
      
  Serial.println("beginVoidLoop");
  
  // Draw Circle 
  // Parametric equation for circle (https://www.mathopenref.com/coordparamcircle.html) 
t = 0;
  while(t < (2*3.14159) ) {
    //Serial.println("While");
    x_new = r*cos(t);
    y_new = r*sin(t);
    dx = x_new-x_old;
    dy = y_new-y_old;

    dA = dx + dy;
    dB = dx - dy;

    // update old and new for delta calcs
    x_old = x_new;
    y_old = y_new;
           
    
    Serial.println(t);
    Serial.println(x_new);

    //Serial.println(dA);
    //Serial.println(dB);

    stepper1.step(dA*miniStep*1);
    stepper2.step(dB*miniStep*1);
    t = t + 0.01;

    
    delay(1); // 1 ms delay for computer to not get confused
  }


  //Serial.println("Forward");

     }

}
  
