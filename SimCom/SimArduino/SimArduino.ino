byte clr;

void setup() {
  Serial.begin(9600);
  pinMode(SS , INPUT);
  pinMode(SCK , INPUT);
  digitalWrite(MISO,LOW);
  pinMode(MISO , OUTPUT);
  pinMode(MOSI , INPUT);
  
  //clear SPI registers
  SPCR = B00000000;
  SPDR = B01011101;
  SPCR = B01000100;
  
  //Set Start Byte
 
  Serial.println("Startup finished   by SIM");
   Serial.println("Waiting for 3G   by SIM");
 

}

void loop() {
  

}

