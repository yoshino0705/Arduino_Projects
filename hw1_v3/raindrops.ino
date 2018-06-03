/*GLOBAL VARIABLES HERE*/
const byte LED_PINS[] = {3, 9, 10, 11};
const byte NUM_OF_LED = 4;
const byte NUM_OF_CYCLES = 6;
const unsigned int DELAY = 10;
const int PATTERN[NUM_OF_CYCLES][NUM_OF_LED] = {
  {HIGH, LOW, LOW, LOW},
  {LOW, HIGH, LOW, LOW},
  {LOW, LOW, HIGH, LOW},
  {LOW, LOW, LOW, HIGH},
  {LOW, LOW, HIGH, LOW},
  {LOW, HIGH, LOW, LOW},
};
unsigned int n;
byte iter;

void fade_down_led(byte led_pin){
  byte brightness = 250;
  byte dim_step = 10;
  while (brightness >= 1){
    analogWrite(led_pin, brightness);
    brightness -= dim_step;
    delay(DELAY);
  }
  analogWrite(led_pin, 0); // completely turn off LED
}

void bright_up_led(byte led_pin){
  byte brightness = 0;
  byte rise_step = 10;
  while (brightness < 250){
    analogWrite(led_pin, brightness);
    brightness += rise_step;
    delay(DELAY);
  }
}

void do_stuff(unsigned int num){
  byte current_cycle = n % NUM_OF_CYCLES;
  for (iter = 0; iter < NUM_OF_LED; iter ++){
    if (PATTERN[current_cycle][iter] == HIGH){
      bright_up_led(LED_PINS[iter]);
      fade_down_led(LED_PINS[iter]);
    }
      
  }
}

void setup() {
  n = 0; // initialize n as 0
  iter = 0; // initialize iter as 0
  for (iter = 0; iter < NUM_OF_LED; iter ++)
    pinMode(LED_PINS[iter], OUTPUT);  // set all LED PINS to output
}

void loop() {
  do_stuff(n);
  n++;
}
