/*GLOBAL VARIABLES HERE*/
const byte NUM_OF_LED = 4;
const byte NUM_OF_CYCLES = 7;
const byte LED_PINS[] = {3, 9, 10, 11};
const unsigned int DELAY = 100;
byte iter;
byte current_cycle;
boolean current_status;
int brightness[NUM_OF_CYCLES][NUM_OF_LED] = {
  {250,0,0,0},
  {100,250,0,0},
  {50,100,250,0},
  {5,50,100,250},
  {0,5,50,100},
  {0,0,5,50},
  {0,0,0,5},
};

void apply_brightness(int brightnesses[NUM_OF_LED]){
  for (iter = 0; iter < NUM_OF_LED; iter ++)
    analogWrite(LED_PINS[iter], brightnesses[iter]);  
}

void apply_brightness_reversed(int brightnesses[NUM_OF_LED]){
  for (iter = 0; iter < NUM_OF_LED; iter ++)
    analogWrite(LED_PINS[iter], brightnesses[3 - iter]);  
}

void setup() {
  iter = 0; // initialize iter as 0
  current_cycle = 0;
  current_status = true;
}

void loop() {
  if (current_cycle >= NUM_OF_CYCLES){
    current_cycle = 0;
    current_status = !current_status;
  }
  if (current_status)
    apply_brightness(brightness[current_cycle]);
  else
    apply_brightness_reversed(brightness[current_cycle]);
  current_cycle ++;
  delay(DELAY);
}
