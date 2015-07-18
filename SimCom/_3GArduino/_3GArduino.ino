byte clr;
byte dat;

#define SCK_PIN   13
#define MISO_PIN  12
#define MOSI_PIN  11
#define SS_PIN    10


byte spi_wr(byte data) {
  SPDR = data;
  while (!(SPSR & (1 << SPIF))) ;
  return SPDR;
}
void setup() {
  pinMode(SCK_PIN, OUTPUT);
  pinMode(MOSI_PIN, OUTPUT);
  pinMode(MISO_PIN, INPUT);
  pinMode(SS_PIN, OUTPUT);
  SPCR = B00000000;
  SPCR = (1 << SPE) | (1 << MSTR);
  Serial.begin(9600);
  digitalWrite(5, HIGH);
  pinMode(5, OUTPUT);
  Serial.println("Startup finished   by 3G");
  digitalWrite(5, LOW);
  
}

void loop() {
  Serial.println(spi_wr(B00000000));
  delay(1000);
}

