byte spi_rw(byte data) {
  while (!(SPSR & (1 << SPIF))) ;
  return SPDR;
  SPDR = data;
}
byte spi_r () {
  while (!(SPSR & (1 << SPIF))) ;
  return SPDR;
}

void setup() {
  cli();
  //Disable Global Interrupts

  PORTD =  PORTD | B00000000;
  //  7-0 Output: HIGH/LOW    INPUT:
  //  D7   D6   D5   D4   D3   D2   D1   D0
  //  XX   XX   XX   I/O  Clk  Rst  TXD  RXD
  //  

  PORTB = PORTB | B00000000;
  //  13-8 OUTPUT: HIGH/LOW   INPUT:
  //  XX   XX   D13  D12  D11  D10  D9   D8
  //  XX   XX   SCK  MISO MOSI SS   XX   XX
  //  

  DDRD = DDRD | B00011100;
  //  7-0 OUTPUT/INPUT
  //  D7   D6   D5   D4   D3   D2   D1   D0
  //  XX   XX   XX   I/O  Clk  Rst  TXD  RXD
  //                 1    1    1

  DDRB = DDRB | B00010000;
  //  13-8 OUTPUT/INPUT
  //  XX   XX   D13  D12  D11  D10  D9   D8
  //  XX   XX   SCK  MISO MOSI SS   XX   XX
  //                 1

  SPCR = B00000000;
  //Reset SPI Controll Register

  SPCR = (1 << SPE);
  //Set SPI Settings: SPiEnabeled
  Serial.begin(9600);
  Serial.println("SIM: Startup finished");
}

void loop() {
  while (B00010000 != spi_rw(B00001000)) {};    //Wait for sync
  Serial.println("SIM: Found 3G");
  while (true) {
    DDRD = spi_rw(PIND) & B11111100;
  }
}

