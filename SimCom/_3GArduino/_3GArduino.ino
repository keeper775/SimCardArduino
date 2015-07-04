byte clr;
byte dat;

byte spi_transfer(byte data)
{
  SPDR = data;                    // Start the transmission
  while (!(SPSR & (1 << SPIF)))   // Wait the end of the transmission
  {
  };
  return SPDR;                    // return the received byte
}

void setup() {
  
  SPCR = B00000000;
  SPDR = B00000000;
  Serial.begin(9600);
  pinMode(MISO , INPUT);
  pinMode(SS , OUTPUT);
  SPCR = B01010100;

  pinMode(MOSI , OUTPUT);
  pinMode(SCK , OUTPUT);
  Serial.println("Startup finished   by 3G");
  Serial.println("Waiting for SIM   by 3G");
  
  dat = spi_transfer(B10000000);
  Serial.println(dat, BIN);
  dat = spi_transfer(B01000000);
  Serial.println(dat, BIN);
  dat = spi_transfer(B00100000);
  Serial.println(dat, BIN);
  dat = spi_transfer(B00010000);
  Serial.println(dat, BIN);
}

void loop() {

}

