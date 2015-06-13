#define Clk 3
#define IO 4
#define Rst 5
#define Vcc 6
unsigned long maxWait = 372000;
unsigned long nextBitTime;
unsigned long endTime;
unsigned long start = 0;
unsigned long wwt = 0;
unsigned long maxwwt = 0;
int data = 0;
int etu = 93;
int guardTime = 186;
boolean startbitFound = 0;
void setup() {
  Serial.begin(9600);
  pinMode(Clk, OUTPUT);
  pinMode(IO, OUTPUT);
  pinMode(Rst, OUTPUT);
  pinMode(Vcc, OUTPUT);

  digitalWrite(Clk, LOW);
  digitalWrite(IO, LOW);
  digitalWrite(Rst, LOW);
  digitalWrite(Vcc, LOW);

  pinMode(IO, INPUT);
  Serial.print("Starting .");

  TCCR2A = B00100011;
  TCCR2B = B00001001;
  OCR2A = 3;
  OCR2B = 1;
  digitalWrite(Rst, HIGH);
  delayMicroseconds(etu * 390);
  while (digitalRead(IO) == HIGH) {}
  // time for 1st data bit
  nextBitTime = micros() + etu + etu / 2;
  // timout calc
  endTime = micros() + maxWait;
  Serial.println("found Startbit");
  while (digitalRead(IO) == LOW) {}
  start = micros();
  while (digitalRead(IO) == HIGH) {}
  etu = (micros() - start) / 3;
  guardTime = etu * 2;
  Serial.println(etu);
  Serial.println(guardTime);
  //wwt = 1920 * etu;
  //maxwwt = wwt + 480 * etu;
  endTime = micros() + maxWait;
  Serial.println(endTime);
  for (int bit = 8; bit = 0; bit--) {
    while (micros() < nextBitTime) {
      if (digitalRead(IO) == 1) {
        bitSet(data, 0);

      }
    }
    nextBitTime = micros() + etu;
    data = data << 1;

  }
  Serial.println(data, BIN);
  Serial.println(56, BIN);
}
void loop() {
}

