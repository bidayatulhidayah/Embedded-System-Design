int A = 2;   // Switch A
int B = 3;   // Switch B
int C = 4;   // Switch C
int D = 5;   // Switch D
int E = 6;   // Switch E
int currentState = 0;
int previousState = 0;
int count[5];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A, INPUT_PULLUP);
  pinMode(B, INPUT_PULLUP);
  pinMode(C, INPUT_PULLUP);
  pinMode(D, INPUT_PULLUP);
  pinMode(E, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  countUpdate(A);
  countUpdate(B);
  countUpdate(C);
  countUpdate(D);
  countUpdate(E);
  
  delay(400);
}

void countUpdate(int pin) {
  currentState = digitalRead(pin);
  
  if (currentState != previousState) {
    if (currentState == LOW) {
      count[pin - 2]++; // Increment count when switch is pressed
    }
  }

  previousState = currentState;
  
  Serial.print("A = "); Serial.print(count[0]); Serial.print("   ");
  Serial.print("B = "); Serial.print(count[1]); Serial.print("   ");
  Serial.print("C = "); Serial.print(count[2]); Serial.print("   ");
  Serial.print("D = "); Serial.print(count[3]); Serial.print("   ");
  Serial.print("E = "); Serial.print(count[4]); Serial.print('\n');
}