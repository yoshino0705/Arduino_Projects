/*GLOBAL VARIABLES HERE*/
const byte LED_PINS[] = {10, 11, 12, 13};
const byte NUM_OF_LED = 4;
unsigned int n;
byte iter;

byte get_led_pin(unsigned int num){
  if (num % 8 == 0 || num % 8 == 1)
    return LED_PINS[0];
  else if (num % 8 == 2 || num % 8 == 7)
    return LED_PINS[1];
  else if (num % 8 == 3 || num % 8 == 6)
    return LED_PINS[2];
  else
    return LED_PINS[3];
}

void light_up_led(unsigned int num){
  byte current_led = get_led_pin(num);
  for (iter = 0; iter < NUM_OF_LED; iter ++)
    digitalWrite( LED_PINS[iter], ( LED_PINS[iter] == current_led) ? HIGH : LOW );
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
  delay(100);
}
