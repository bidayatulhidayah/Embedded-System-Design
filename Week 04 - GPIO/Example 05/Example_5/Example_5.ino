unsigned int count;
bool previous;
unsigned char *reader = (unsigned char*) 0x23;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600); //For now, we are still using the Serial library
 for (;;)
 {
    bool current = (((*reader) & 0b00010000)!= 0);
    if (current && !previous) //If the pin is currently HIGH and previously LOW
    {
    count++;
    Serial.println(count);
    }
    previous = current;
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
