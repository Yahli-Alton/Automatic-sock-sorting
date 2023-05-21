#include <Servo.h>

// int num=1;
// int color1 = 0;

Servo sorterServo;
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
