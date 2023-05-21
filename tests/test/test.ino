String a;
void setup() {
    Serial.begin(9600);
}

void loop() {
    // Serial.println("Hello World!");
    while (Serial.available() == 0) {
    }
    a = Serial.readString();
    Serial.println(a);
}