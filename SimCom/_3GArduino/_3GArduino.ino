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
  Serial.begin(9600);
  digitalWrite(MOSI, LOW);
  digitalWrite(6 , HIGH);
  
  pinMode(MISO , INPUT);
 
  pinMode(SS , OUTPUT);
  pinMode(6 , OUTPUT);


  SPCR = B01010100;
  //clear SPI registers
  //Set Start Byte
  pinMode(MOSI , OUTPUT);
  pinMode(SCK , OUTPUT);
  //Set as Master
  Serial.println("Startup finished   by 3G");
  digitalWrite(6, LOW);
  Serial.println("Waiting for SIM   by 3G");
  delay(10000);
  dat = spi_transfer(B10000000);

  Serial.println(dat, BIN);
  dat = spi_transfer(B10000000);

  Serial.println(dat, BIN);
  dat = spi_transfer(B10000000);

  Serial.println(dat, BIN);
  dat = spi_transfer(B10000000);

  Serial.println(dat, BIN);
}

void loop() {

}

