void setup() {
  Serial.begin(9600);
  Serial.println("Startup finished by 3g");
  pinMode(MISO , INPUT);
  pinMode(SS , INPUT_PULLUP);
  pinMode(SCK , OUTPUT);
  pinMode(MOSI , OUTPUT);
  do{SPDR = B10000000;
  while(!(SPSR & (1<<SPIF)));
}

void loop() {
  // put your main code here, to run repeatedly:

}
