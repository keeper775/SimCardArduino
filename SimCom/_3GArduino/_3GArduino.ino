byte spi_wr(byte data) {
  SPDR = data;
  while (!(SPSR & (1 << SPIF))) {}; //Wait for Arduino to finish transmition
  return SPDR;
}
void setup() {
  cli();                           //Disable Global Interrupts
  PORTD =  PORTD | B00000000;
  //  7-0 Output: HIGH/LOW    INPUT:
  //  D7   D6   D5   D4   D3   D2   D1   D0
  //  XX   XX   XX   I/O  Clk  Rst  TXD  RXD
  //  

  PORTB = PORTB | B00000100;
  //  13-8 OUTPUT: HIGH/LOW   INPUT:
  //  XX   XX   D13  D12  D11  D10  D9   D8
  //  XX   XX   SCK  MISO MOSI SS   XX   XX
  //                           1

  DDRD = DDRD | B00000000;
  //  7-0 OUTPUT/INPUT
  //  D7   D6   D5   D4   D3   D2   D1   D0
  //  XX   XX   XX   I/O  Clk  Rst  TXD  RXD
  //                      

  DDRB = DDRB | B00101100;
  //  13-8 OUTPUT/INPUT
  //  XX   XX   D13  D12  D11  D10  D9   D8
  //  XX   XX   SCK  MISO MOSI SS   XX   XX
  //            1         1    1
  SPCR = B00000000;
  //Reset SPI Controll Register
  SPCR = (1 << SPE) | (1 << MSTR);
  //Set SPI Settings: SPiEnabeled , MaSTeR
}

void loop() {

  spi_wr(2);

}


