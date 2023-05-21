#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

extern int const arrayLength = 7;

int const max_color_count = 3;

int const red_different = 6;
int const green_different = 4;
int const blue_different = 3;

int redFrequency = 0; // The amount of red color
int greenFrequency = 0; // The amount of green color
int blueFrequency = 0; // the amount of blue color

// create new array of length 5

int colors[arrayLength][3];

int color[3];

int tempColor[3];

int color_count = 0;


boolean started_counting = false;
boolean was_default_color_before = true;

int default_color[3];

int i = 0;
int j = 0;

int red = 0;
int blue = 0;
int green = 0;

// functions:

void set(int color1[3], int color2[3]) {
  color1[0] = color2[0];
  color1[1] = color2[1];
  color1[2] = color2[2];
}

boolean colors_equels(int color1[3], int color2[3]) {
  return abs(color1[0] - color2[0]) < red_different && abs(color1[1] - color2[1]) < green_different && abs(color1[2] - color2[2]) < blue_different;
}

void Sensor_setup() { // run only once
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

// return array of 3 ints: red, green, blue
int * getColor() {
  // Setting RED (R) filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  redFrequency = pulseIn(sensorOut, LOW);
  delay(100);
  
  // Setting GREEN (G) filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  greenFrequency = pulseIn(sensorOut, LOW);
  delay(100);
 
  // Setting BLUE (B) filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  blueFrequency = pulseIn(sensorOut, LOW);
  delay(100);
  
  color[0] = redFrequency;
  color[1] = greenFrequency;
  color[2] = blueFrequency;

  return color;
}

int check_for_sock() {
  if (default_color[0] == 0) {
    set(default_color, color);
  }

  if (colors_equels(default_color, color)) {
    was_default_color_before = true;
  }
  else {
    if (!started_counting && was_default_color_before) {
      set(tempColor, color);
      started_counting = true;
      was_default_color_before = false;
    }
  }

  if (started_counting) {
    if (colors_equels(tempColor, color)) {
      color_count++;
    //   Serial.print("counting: ");
    //   Serial.print(color_count);
    //   Serial.print(" ");
    } else {
      color_count = 0;
      started_counting = false;
      was_default_color_before = true; // Even though it isn't true, we want to start the counting again so we have to
    }
  }
  if (color_count > max_color_count) {
    j = 0;
    for (int j = 0; j < arrayLength; j++) {
      // Serial.print(" IN LOOP: ");
      if (colors_equels(colors[j], color)) {
        color_count = 0;
        started_counting = false;
        // Serial.println("");
        // Serial.print("RETURN: ");
        // Serial.print(j);
        // Serial.println("");
        return j;
      }
    }
    set(colors[i], color);
    color_count = 0;
    started_counting = false;
    if (i < arrayLength - 1) {
        i += 1;
        return i - 1;
    }
    return i;
  }
  return -1;
}