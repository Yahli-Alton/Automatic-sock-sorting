#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8


int redFrequency = 0; // The amount of red color
int greenFrequency = 0; // The amount of green color
int blueFrequency = 0; // the amount of blue color

int red = 0;
int blue = 0;
int green = 0;

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
  red = map(redFrequency, 3,30,255,0);
  // red = red * 1.5 - 127;
  if (red > 255) red = 255;
  if (red < 0) red = 0;
   // Printing the RED (R) value
  // Serial.print("R = ");
  Serial.print(redFrequency);
  delay(100);
  
  // Setting GREEN (G) filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  
  // Reading the output frequency
  greenFrequency = pulseIn(sensorOut, LOW);
  green = map(greenFrequency, 4, 40, 255,0);
  // green = green * 1.5 - 127;
  if (green > 255) green = 255;
  if (green < 0) green = 0;
  // green = map(greenFrequency, 25,70,255,0);
  // Printing the GREEN (G) value  
  Serial.print(",");
  Serial.print(greenFrequency);
  delay(100);
 
  // Setting BLUE (B) filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  
  // Reading the output frequency
  blueFrequency = pulseIn(sensorOut, LOW);
  blue = map(blueFrequency, 3,40,255,0);
  // blue = blue * 1.5 - 127;
  if (blue > 255) blue = 255;
  if (blue < 0) blue = 0;
  // Printing the BLUE (B) value 
  Serial.print(",");
  Serial.print(blueFrequency);
  delay(100);

  // if (blue > 280) Serial.print(" Blue");
  // if (red > 280) Serial.print(" Red");


  // if (blue > red && blue > green) Serial.print(" Blue");
  // if (red > blue && red > green) Serial.print(" Red");
  // if (green > red && green > blue) Serial.print(" Green");

  Serial.println();  
}

