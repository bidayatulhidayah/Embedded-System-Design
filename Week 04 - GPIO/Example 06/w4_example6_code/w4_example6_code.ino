////////////// Variables for blinking LED ////////////////////
unsigned long previousTime; 
unsigned char *D_dir = (unsigned char*) 0x2A; 
unsigned char *D_writer = (unsigned char*) 0x2B; 
////////////// Variables for debouncing////////////////////
unsigned int count;
bool previous;
bool waiting;
unsigned long pressed_time;
unsigned char *B_reader = (unsigned char*) 0x23; 

void setup() {
  // put your setup code here, to run once:
  *D_dir = 0b00000100;
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  //Code to perform other functions (such as LED blinking) can be inserted here
  BlinkLED(); //BlinkLED handles stuff for blinking PD2
  DebounceButton(); //DebounceButton handles stuff for debouncing PB4
}

void BlinkLED() {
  unsigned long currentTime = millis();
  if (((*D_writer) & 0b00000100) == 0) //If the LED is currently OFF 
  {
    if (currentTime - previousTime >= 2000) //2000 is OFF duration
    {
      *D_writer |= 0b00000100; //Turn ON the LED
      previousTime = currentTime; //Take note of the time
    } 
  }
  else //LED is currently ON
  {
    if (currentTime - previousTime >= 2000) //2000 is ON duration
    {
      *D_writer &= 0b11111011; //Turn OFF the LED
      previousTime = currentTime; //Take note of the time
    }
  }
}

void DebounceButton() {
  if (waiting) 
  {
    if (millis() - pressed_time >= 20) //20ms is the debounce period. (If the debounce period has elapsed)
    {
      waiting = 0;
      bool current = (((*B_reader) & 0b00010000)!= 0); //current = HIGH if input PB4 is HIGH
      if (current) //If PB4 is still HIGH, it means it is a real LOW to HIGH transition
      {
        count++;
        Serial.println(count);
      }
      previous = current; 
    } 
  } 
  else
  {
    bool current = (((*B_reader) & 0b00010000)!= 0); //current = HIGH if input PB4 is HIGH
    if (current && !previous) //If the PB4 is currently HIGH and previously LOW (LOW to High transition)
    {
      pressed_time = millis(); //Take note of the time and then start waiting 
      waiting = 1;
    }
    previous = current;
  }
}