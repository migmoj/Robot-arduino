

#include <IRLib.h>

int RECV_PIN = 11;
int MOTOR1DE = 5;  //Motor uno adelante
int MOTOR1AT = 6;  //Motor uno atras
int MOTOR2DE = 9;
int MOTOR2AT = 10;
int velocidad = 0;

IRrecv My_Receiver(RECV_PIN);

IRdecode My_Decoder;
unsigned int Buffer[RAWBUF];

void setup()
{
  Serial.begin(9600);
    My_Receiver.enableIRIn(); // Start the receiver
  My_Decoder.UseExtnBuf(Buffer);
   pinMode(MOTOR1DE, OUTPUT);
   pinMode(MOTOR1AT, OUTPUT);
   pinMode(MOTOR2DE, OUTPUT);
   pinMode(MOTOR2AT, OUTPUT);
 
  analogWrite(MOTOR1DE, 0);
  analogWrite(MOTOR1AT, 0);
  analogWrite(MOTOR2DE, 0);
  analogWrite(MOTOR2AT, 0);
}

void loop() {

  analogWrite(MOTOR1DE, velocidad);
  
  if (My_Receiver.GetResults(&My_Decoder)) {
    My_Receiver.resume(); 
    My_Decoder.decode();
    //My_Decoder.DumpResults();
    Serial.println(My_Decoder.value);
     
  }
  if (My_Decoder.value == 16747125){
    velocidad = 120;
    Serial.println (velocidad);
  } 
  if (My_Decoder.value == 16714485){
    velocidad = 0;
    Serial.println (velocidad);
  } 
   delay(100);
}
/* 
  
mando fino 
16747125   1
16714485   2
16716525   3
16764975   4
16754775   5
16748655   6
16750695   7
16767015   8
16738455   9
16742535   0
16728255   ar
16773135   iz
16769055   de
16712445   ab
16756815   izrr
16744575   derr
16752735   izln
16746615   deln
*/
