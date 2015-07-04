byte clr;
byte dat;

byte spi_recieve()
{                 
  while (!(SPSR & (1 << SPIF)))   // Wait the end of the transmission
  {
  };
  return SPDR;                    // return the received byte
}

void setup() {
 SPCR = B00000000;
  SPDR = B11110000;
  Serial.begin(9600);
  pinMode(SS , INPUT);
  pinMode(SCK , INPUT);
  pinMode(MISO , OUTPUT);
  pinMode(MOSI , INPUT);
  
  //clear SPI registers
  
  SPCR = B01000100;
  
  //Set Start Byte
 
  Serial.println("Startup finished   by SIM");
   Serial.println("Waiting for 3G   by SIM");

}

void loop() {
dat=spi_recieve();
Serial.println(dat,BIN);
}

