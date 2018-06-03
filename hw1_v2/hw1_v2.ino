/*GLOBAL VARIABLES HERE*/
const byte LED_PINS[] = {10, 11, 12, 13};
const byte NUM_OF_LED = 4;
const byte NUM_OF_CYCLES = 12;
const unsigned int DELAY = 500;
const int PATTERN[NUM_OF_CYCLES][NUM_OF_LED] = {
  {HIGH, LOW, LOW, LOW},
  {LOW, HIGH, LOW, LOW},
  {LOW, LOW, HIGH, LOW},
  {LOW, LOW, LOW, HIGH},
  {LOW, LOW, LOW, HIGH},
  {LOW, LOW, HIGH, LOW},
  {LOW, HIGH, LOW, LOW},
  {HIGH, LOW, LOW, LOW},
  {HIGH, HIGH, HIGH, HIGH},
  {LOW, LOW, LOW, LOW},
  {HIGH, HIGH, HIGH, HIGH},
  {LOW, LOW, LOW, LOW},
};
unsigned int n;
byte iter;

void light_up_led(unsigned int num){
  byte current_cycle = n % NUM_OF_CYCLES;
  for (iter = 0; iter < NUM_OF_LED; iter ++)
    digitalWrite( LED_PINS[iter],  PATTERN[current_cycle][iter]);
}

void setup() {
  n = 0; // initialize n as 0
  iter = 0; // initialize iter as 0
  for (iter = 0; iter < NUM_OF_LED; iter ++)
    pinMode(LED_PINS[iter], OUTPUT);  // set all LED PINS to output
}

void loop() {
  light_up_led(n);
  n++;
  delay(DELAY);
}
