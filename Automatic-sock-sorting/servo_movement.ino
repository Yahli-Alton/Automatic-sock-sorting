#include <Servo.h>

// int num=1;
// int color1 = 0;

Servo sorterServo;


int frequency = 0;



void moveBox(int color) {

   switch (color) {
  case 1:
   sorterServo.writeMicroseconds(1000);
    delay(400);
  sorterServo.writeMicroseconds(1500);
  delay(3000);
    sorterServo.writeMicroseconds(2000);
        delay(350);
          sorterServo.writeMicroseconds(1500);


    break;

     case 2:
    sorterServo.writeMicroseconds(1000);
     delay(750);
  sorterServo.writeMicroseconds(1500);
   delay(3000);
    sorterServo.writeMicroseconds(2000);
        delay(700);
          sorterServo.writeMicroseconds(1500);


     break;

     case 3:
      sorterServo.writeMicroseconds(1000);
       delay(1050);
  sorterServo.writeMicroseconds(1500);
  delay(3000);
    sorterServo.writeMicroseconds(2000);
        delay(970);
          sorterServo.writeMicroseconds(1500);
    break;

     case 4:
     sorterServo.writeMicroseconds(1000);
      delay(1350);
  sorterServo.writeMicroseconds(1500);
  delay(3000);
   sorterServo.writeMicroseconds(2000);
        delay(1300);
          sorterServo.writeMicroseconds(1500);

  
     break;

    
    
     case 0:
     break;
  }
}


void servomovment(){
 sorterServo.attach(3);

  Serial.begin(9600);

  delay(500);
}
int colorMatch(int color1){
switch(color1){

    case 0:
    break;
    
    case 1:
    sorterServo.write(50);
    break;

    case 2:
    sorterServo.write(75);
    break;

    case 3:
    sorterServo.write(100);
    break;

    case 4:
    sorterServo.write(125);
    break;
 }
}
