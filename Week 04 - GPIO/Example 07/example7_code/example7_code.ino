class Blinky {
private:
  char port;                     // Port of the LED
  int pin;                       // Pin number of the LED
  unsigned long onTime;          // ON time duration in milliseconds
  unsigned long offTime;         // OFF time duration in milliseconds
  unsigned long previousMillis;  // Time at which LED was last updated
  bool state;                    // Current state of the LED

public:
  // Constructor
  Blinky(char p, int _pin, unsigned long _onTime, unsigned long _offTime) {
    port = p;
    pin = _pin;
    onTime = _onTime;
    offTime = _offTime;
    previousMillis = 0;
    state = LOW;
    pinMode(pin, OUTPUT);
  }

  // Method to refresh the LED state
  void Refresh() {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= (state ? onTime : offTime)) {
      state = !state;
      digitalWrite(pin, state);
      previousMillis = currentMillis;
    }
  }
};

// Create instances of the Blinky class for LED0 and LED1
Blinky led0('B', 0, 750, 350);
Blinky led1('B', 1, 400, 600);

void setup() {
  // put your setup code here, to run once:
  while(1)
  {
    led0.Refresh();
    led1.Refresh(); 
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
