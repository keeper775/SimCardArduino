
#define Vcc 2
#define Clk 3
#define IO 4
#define Rst 5

void setup() {
  Serial.begin(9600);
  pinMode(MISO , INPUT);
  pinMode(SS , INPUT_PULLUP);
  pinMode(SCK , OUTPUT);
  pinMode(MOSI , OUTPUT);
  Serial.println("Startup finished by 3g");


}

void loop() {
  //Set SPI data register available bit
  SPDR = B10000000;
  //Wait for first data transmition
  while (!(SPSR & (1 << SPIF)));
  if (SPDR == B01000000) {
    Serial.println("Connection established by 3G");
  }
}

