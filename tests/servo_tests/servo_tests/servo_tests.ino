#include <Servo.h>


Servo bottomServo;

int frequency = 0;
int color=0;

void setup() {
  
  bottomServo.attach(9);

  Serial.begin(9600);
  
}
  void loop() {
bottomServo.write(50);


   
  }


