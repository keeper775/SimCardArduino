#define Clk 3
#define IO 4
#define Rst 5
#define MOSI 0
#define MISO 0
#define SCK 
void setup(
Serial.begin(9600)
pinMode(Clk, OUTPUT);
pinMode(Rst, OUTPUT);
pinMode(IO, INPUT);
pinMode()
TCCR2A = B00100011;
TCCR2B = B00001001;
OCR2A = 3;
OCR2B = 1;
Serial.println("Startup finished... Waiting for SPI from Master")
SPCR = 
SPIF

)
