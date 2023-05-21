int box;

void setup() {
  Sensor_setup();
  Serial.setTimeout(1);
}

void loop() { // run repeatedly
  getColor();
  box = check_for_sock();
  if (box != -1) {
    // call for servo_move(box);
    Serial.println(box);
    colorMatch(box);
  }
  if (Serial.available()) { // get the box from python
    box = Serial.readString().toInt();
    Serial.print(box);
  }
}