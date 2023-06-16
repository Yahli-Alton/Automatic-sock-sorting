#include <Servo.h>

int box;
bool short_ = false;
bool long_ = false;
int const arrayLength2 = 5;
int x = -1;
int colors_size[arrayLength2][5];

Servo bottomServo;
Servo conveyerServo;
Servo conveyerServo2;
Servo picServo;

void setup() {
  Sensor_setup();
  Serial.setTimeout(1);
  bottomServo.attach(11);
  conveyerServo.attach(13);
  picServo.attach(12);
  // conveyerServo2.attach(11);




}

void loop() { // run repeatedly
  getColor();
  box = check_for_sock();
  // Serial.println("hello");
  if (box != -1) {
    // call for servo_move(box);
    Serial.println(box);
    moveBox(box);
  }
  
  conveyerServo.writeMicroseconds(2000);
  picServo.writeMicroseconds(2000);
  // conveyerServo2.writeMicroseconds(1000);

  // if (Serial.available()) { // get the box from python
  //   x = Serial.readString().toInt();
  //   if (x == 0) {
  //     Serial.print("SHORT");
  //   }
  //   Serial.print(box);
  // }
}