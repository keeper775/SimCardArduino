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
unsigned int data = 0;
int etu = 93;
int guardTime = 186;
boolean startbitFound = 0;
void setup() {
  Serial.begin(9600);
  pinMode(Clk, OUTPUT);
  pinMode(Rst, OUTPUT);
  pinMode(Vcc, OUTPUT);
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
  while (digitalRead(IO) == LOW) {start = micros();}
  // falling edge of third bit
do  { etu = ((micros() - start) / 3)+2;}
while (digitalRead(IO) == HIGH);
  Serial.println("4. Calc Etu");
  Serial.print("etu:    ");
  Serial.println(etu);
  guardTime = etu * 2;
  //wwt = 1920 * etu;
  //maxwwt = wwt + 480 * etu;
  delay(10);
   nextBitTime = micros() + etu + etu / 2;
  endTime = micros() + maxWait;
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
}
void loop() {
}
