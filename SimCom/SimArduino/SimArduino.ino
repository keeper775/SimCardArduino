#define Vcc 2
#define Clk 3
#define IO 4
#define Rst 5
void setup() {
  Serial.begin(9600);
  pinMode(Clk, OUTPUT);
  pinMode(Rst, OUTPUT);
  pinMode(IO, INPUT);
  pinMode(SCK, INPUT);
  pinMode(MOSI, INPUT);
  pinMode(MISO, OUTPUT);
  TCCR2A = B00100011;
  TCCR2B = B00001001;
  OCR2A = 3;
  OCR2B = 1;
  Serial.println("Startup finished by Sim");
}
void loop() {
  SPDR = B01000000;
  SPCR = B01010000;
  //Wait for first data transmition
  while (!(SPSR & (1 << SPIF))){};
  if (SPDR == B10000000) {
    Serial.println("Connection established by Sim");
  }
}

