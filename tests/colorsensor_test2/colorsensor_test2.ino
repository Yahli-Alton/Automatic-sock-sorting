#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8


int redFrequency = 0; // The amount of red color
int greenFrequency = 0; // The amount of green color
int blueFrequency = 0; // the amount of blue color

// create new array of length 5
int colors[5][3];

int color[3];

int default_color[3];

int i = 0;

int red = 0;
int blue = 0;
int green = 0;

int const red_different = 5;
int const green_different = 5;
int const blue_different = 5;

void set(int color1[3], int color2[3]) {
  color1[0] = color2[0];
  color1[1] = color2[1];
  color1[2] = color2[2];
}

boolean colors_equels(int color1[3], int color2[3]) {
  return abs(color1[0] - color2[0]) < red_different && abs(color1[1] - color2[1]) < green_different && abs(color1[2] - color2[2]) < blue_different;
}


void setup() { // run only once
  // Setting the outputs - set s0, s1, s2,s3 as the output of the colorsensor
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);

  // set the sensorOut as input
  pinMode(sensorOut, INPUT);
  // Begins serial communication - the speed of the communication
  Serial.begin(9600);

  digitalWrite(S1, HIGH);
  digitalWrite(S0, HIGH);
}

void loop() { // run repeatedly
  // Setting RED (R) filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  
  // Reading the output frequency
  redFrequency = pulseIn(sensorOut, LOW);
   // Printing the RED (R) value
  // Serial.print("R = ");
  // Serial.print(redFrequency);
  delay(100);
  
  // Setting GREEN (G) filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  
  // Reading the output frequency
  greenFrequency = pulseIn(sensorOut, LOW);
  // green = map(greenFrequency, 25,70,255,0);
  // Printing the GREEN (G) value  
  // Serial.print(",");
  // Serial.print(greenFrequency);
  delay(100);
 
  // Setting BLUE (B) filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  
  // Reading the output frequency
  blueFrequency = pulseIn(sensorOut, LOW);
  // Printing the BLUE (B) value 
  // Serial.print(",");
  // Serial.print(blueFrequency);
  delay(100);

  color[0] = redFrequency;
  color[1] = greenFrequency;
  color[2] = blueFrequency;
  
 if (default_color[0] == 0) {
    set(default_color, color);
  }

  if (!colors_equels(default_color, colors[i])) {
    set(colors[i], color);
    if (i < 4) i++;
  }

  for (int i = 0; i < 3; i++) {
    Serial.print(default_color[i]);
    Serial.print(",");
  }
  Serial.print(" - ");
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 3; j++) {
      Serial.print(colors[i][j]);
      Serial.print(",");
    }
    Serial.print(" ");
  }


  Serial.println();  
}

