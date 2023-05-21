int box;

void setup() {
  Sensor_setup();
}

void loop() { // run repeatedly
  box = check_for_sock();
  if (box != -1) {
    // call for servo_move(box);
  }
}