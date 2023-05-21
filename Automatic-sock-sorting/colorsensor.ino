#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

extern int const arrayLength = 5;

int const max_color_count = 3;

int const red_different = 4;
int const green_different = 4;
int const blue_different = 4;

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
boolean returned = false;

int default_color[3];

int i = 0;
int j = 0;

int red = 0;
int blue = 0;
int green = 0;

// functions:
