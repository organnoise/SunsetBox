#define LEDR     9
#define LEDG     6
#define LEDB     5

int r, g, b;

void setup()
{
  bitSet(TCCR1B, WGM12);
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
  r = g = b = 0;
  
  Serial.begin(9600);
  }

void loop()
{
   
  
  if(Serial.available() >= 3)
  {
    r = Serial.read();
    g = Serial.read();
    b = Serial.read();
    Serial.write('1'); // Sync
  }
 
  analogWrite(LEDR, r);
  analogWrite(LEDG, g);
  analogWrite(LEDB, b);
}
