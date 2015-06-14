#define Clk 3
#define IO 4
#define Rst 5
#define Vcc 6
unsigned long nextBitTime;
unsigned long endTime;
unsigned long start = 0;
byte T0 = 0;
int etu = 93;
int guardTime = 186;
void setup() {
  Serial.begin(9600);
  pinMode(Clk, OUTPUT);
  pinMode(Rst, OUTPUT);
  pinMode(Vcc, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(IO, INPUT);
  digitalWrite(Rst, HIGH);
  digitalWrite(Vcc, LOW);


  delay(200);
  Serial.println("1. Starting clock generation");

  TCCR2A = B00100011;
  TCCR2B = B00001001;
  OCR2A = 3;
  OCR2B = 1;
  Serial.println("2. Card Powerup");
  digitalWrite(Vcc, HIGH);
  delayMicroseconds(100);
  digitalWrite(Rst, LOW);
  delayMicroseconds(150);
  digitalWrite(Rst, HIGH);
  delay(4);
  Serial.println("3. Reset sent");

  // falling edge of first bit
  while (digitalRead(IO) == HIGH) {}
  // rising edge of first bit
  while (digitalRead(IO) == LOW) {}
  // falling edge of second bit
  while (digitalRead(IO) == HIGH) {}
  // rising edge of second bit
  while (digitalRead(IO) == LOW) {
    start = micros();
  }
  // falling edge of third bit
  do  {
    etu = ((micros() - start) / 3) + 2;
  }
  while (digitalRead(IO) == HIGH);
  Serial.println("4. Calculate Etu");
  Serial.print("etu:    ");
  Serial.println(etu);
  guardTime = etu * 2;
  Serial.println("5. Calculate Guardtime");
  Serial.print("guardTime: ");
  Serial.println(guardTime);
  delay(10);
  while (digitalRead(IO) == HIGH) {
    nextBitTime = micros() + (etu / 2);
  }

  for (int i = 0; i < 8; i++) {
    while (micros() < nextBitTime) {}
    T0 = T0 << 1;
    if (digitalRead(IO) == 1) {
      bitSet(T0,0);
    }

    nextBitTime = nextBitTime + etu;
  }

 Serial.println("T0: ");
 Serial.print(T0,HEX);

}
void loop() {
}

