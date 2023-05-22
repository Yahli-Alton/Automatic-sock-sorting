int box;
bool short_ = false;
bool long_ = false;
int const arrayLength2 = 7;
int x = -1;
int colors_size[arrayLength2][5];

void setup() {
  Sensor_setup();
  Serial.setTimeout(1);
}

void loop() { // run repeatedly
  getColor();
  box = check_for_sock();
  if (box != -1) {
    for (int i = 0; i < arrayLength2; i++) {
      for (int j = 0; j < 3; j++) {
        colors_size[i][j] = getColors(i, j);
        Serial.print(colors_size[i][j]);
        Serial.print(", ");
      }
      Serial.print(" : ");
    }

    // call for servo_move(box);
    Serial.println(box);
    colorMatch(box);
  }
  if (Serial.available()) { // get the box from python
    x = Serial.readString().toInt();
    if (x == 0) {
      Serial.print("SHORT");
    }
    Serial.print(box);
  }
}