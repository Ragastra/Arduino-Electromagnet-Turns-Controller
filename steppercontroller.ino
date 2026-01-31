// CNC Shield V3 pin mapping (Arduino UNO)
#define X_STEP 2
#define X_DIR  5

#define Y_STEP 3
#define Y_DIR  6

#define ENABLE 8   // common enable for all drivers

void setup() {
  pinMode(X_STEP, OUTPUT);
  pinMode(X_DIR, OUTPUT);
  pinMode(Y_STEP, OUTPUT);
  pinMode(Y_DIR, OUTPUT);
  pinMode(ENABLE, OUTPUT);

  digitalWrite(ENABLE, LOW);   // ENABLE drivers (LOW = ON)
  digitalWrite(X_DIR, HIGH);   // same direction
  digitalWrite(Y_DIR, HIGH);   // same direction
}

void loop() {
  // one step pulse for both motors together
  digitalWrite(X_STEP, HIGH);
  digitalWrite(Y_STEP, HIGH);
  delayMicroseconds(2000);   // ↑ increase = slower

  digitalWrite(X_STEP, LOW);
  digitalWrite(Y_STEP, LOW);
  delayMicroseconds(2000);
}
