#define Clk 3
#define IO 4
#define Rst 5
void setup(){
noInterrupts();
Serial.begin(9600);
pinMode(Clk, OUTPUT);
pinMode(Rst, OUTPUT);
pinMode(IO, INPUT);
pinMode(SCK, INPUT);
pinMode(MOSI, INPUT);
pinMode(MISO, OUTPUT);
TCCR2A = B00100011;
TCCR2B = B00001001;
OCR2A = 3;
OCR2B = 1;
Serial.println("Startup finished... Waiting for SPI from Master");

SPCR = (1<<SPE);

do{
SPDR = B10000000;
while(!(SPSR & (1<<SPIF)));
} while (SPDR !=B01000000);
}
