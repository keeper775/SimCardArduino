#define SCK_PIN   13
#define MISO_PIN  12
#define MOSI_PIN  11
#define SS_PIN    10

byte clr;
byte dat;
int x = 0;

byte spi_rw(byte data) {
  while (!(SPSR & (1 << SPIF))) ;
  return SPDR;
  SPDR = data;
}

void setup() {
  cli();
  Serial.begin(9600);
  pinMode(SCK_PIN, INPUT);
  pinMode(MOSI_PIN, INPUT);
  pinMode(MISO_PIN, OUTPUT);
  pinMode(MISO_PIN, HIGH);
  pinMode(SS_PIN, INPUT);
  delay(200);
  SPCR = B00000000;
  SPDR = 42;
  SPCR = (1 << SPE);
  Serial.println("Startup finished   by SIM");
}

void loop() {
  if (x==200){
  x=1;
  }
  while (!(SPSR & (1 << SPIF))) ;
    SPDR=x;
    x++;
}

