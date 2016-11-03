

#include <IRLib.h>

byte RECV_PIN = 11;
byte MOTOR1DE = 5;  //Motor uno adelante
byte MOTOR1AT = 6;  //Motor uno atras
byte MOTOR2DE = 9;
byte MOTOR2AT = 10;
byte velocidad1 = 0;
byte velocidad2 = 0;
byte velocidad = 0;
int sentido = 1;
int a = 0;

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

   if (a >= 0){
    analogWrite(MOTOR1DE, velocidad1);
    analogWrite(MOTOR2DE, velocidad2);
    analogWrite(MOTOR1AT, 0);
    analogWrite(MOTOR2AT, 0);
  }

  if (a < 0){
     analogWrite(MOTOR1AT, velocidad1);
     analogWrite(MOTOR2AT, velocidad2);
     analogWrite(MOTOR1DE, 0);
     analogWrite(MOTOR2DE, 0);
  }
 delay (100);
  
  if (My_Receiver.GetResults(&My_Decoder)) {
    My_Receiver.resume(); 
    My_Decoder.decode();
    //My_Decoder.DumpResults();
    Serial.println(My_Decoder.value);
     
    if (My_Decoder.value == 16747125){
        velocidad = 120;
           } else
    if (My_Decoder.value == 16714485){
       velocidad = 150;
          } else
    if (My_Decoder.value == 16716525){
       velocidad = 180;
          } else
    if (My_Decoder.value == 16728255){
       sentido = 1;
          } else
     if (My_Decoder.value == 16712445){
       sentido = -1;
          } else
    if (My_Decoder.value == 16742535){
       velocidad = 0;
          } else
    if (My_Decoder.value == 16752735){
        velocidad --;
          } else
    if (My_Decoder.value == 16746615){
       velocidad ++;
          }
    
    a = velocidad * sentido;
    velocidad1 = velocidad;
    velocidad2 = velocidad;

     if (My_Decoder.value == 16773135){
        velocidad1 = 0;
            } else
    if (My_Decoder.value == 16769055){
       velocidad2 = 0;
           }

  
  
   }
   
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
