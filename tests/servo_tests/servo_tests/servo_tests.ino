#include <Servo.h>


Servo bottomServo;

int frequency = 0;
int color=0;

void setup() {
  
  bottomServo.attach(3);

  Serial.begin(9600);
  
    color=4;
  



   switch (color) {
  case 1:
   bottomServo.writeMicroseconds(1000);
    delay(400);
  bottomServo.writeMicroseconds(1500);
  delay(3000);
    bottomServo.writeMicroseconds(2000);
        delay(350);
          bottomServo.writeMicroseconds(1500);


    break;

     case 2:
    bottomServo.writeMicroseconds(1000);
     delay(750);
  bottomServo.writeMicroseconds(1500);
   delay(3000);
    bottomServo.writeMicroseconds(2000);
        delay(700);
          bottomServo.writeMicroseconds(1500);


     break;

     case 3:
      bottomServo.writeMicroseconds(1000);
       delay(1050);
  bottomServo.writeMicroseconds(1500);
  delay(3000);
    bottomServo.writeMicroseconds(2000);
        delay(970);
          bottomServo.writeMicroseconds(1500);
    break;

     case 4:
     bottomServo.writeMicroseconds(1000);
      delay(1350);
  bottomServo.writeMicroseconds(1500);
  delay(3000);
   bottomServo.writeMicroseconds(2000);
        delay(1300);
          bottomServo.writeMicroseconds(1500);

  
     break;

    
    
     case 0:
     break;
  }
}

void loop() {}

