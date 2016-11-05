#include <IRLib.h>

#define RECV_PIN 11
#define MOTOR1DE 5
#define MOTOR1AT 6
#define MOTOR2DE 9
#define MOTOR2AT 10

byte velocidad = 0;


IRrecv My_Receiver(RECV_PIN);

IRdecode My_Decoder;
unsigned int Buffer[RAWBUF];

void setup()
{
  Serial.begin(9600);
    My_Receiver.enableIRIn(); // Start the receiver
  My_Decoder.UseExtnBuf(Buffer);
  
   pinMode(MOTOR1AT, OUTPUT);
   pinMode(MOTOR1DE, OUTPUT);
   pinMode(MOTOR2AT, OUTPUT);
   pinMode(MOTOR2DE, OUTPUT);
 
  analogWrite(MOTOR1AT, 0);
  analogWrite(MOTOR1DE, 0);
  analogWrite(MOTOR2AT, 0);
  analogWrite(MOTOR2DE, 0);
}

void loop() {

 
  
  
  if (My_Receiver.GetResults(&My_Decoder)) {
    My_Receiver.resume(); 
    My_Decoder.decode();
    //My_Decoder.DumpResults();
    Serial.println(My_Decoder.value); 
 
     if (My_Decoder.value == 16747125){
        velocidad = 120;
        adelante();
           } else
    if (My_Decoder.value == 16714485){
       velocidad = 150;
       adelante();
          } else
    if (My_Decoder.value == 16716525){
       velocidad = 180;
       adelante();
          } else
    if (My_Decoder.value == 16728255){
       adelante();
          } else
     if (My_Decoder.value == 16712445){
       atras();
          } else
    if (My_Decoder.value == 16742535){
       parar();
          } else
    if (My_Decoder.value == 16752735){
        velocidad --;
        adelante();
          } else
    if (My_Decoder.value == 16746615){
       velocidad ++;
       adelante();
          }
    
  

     if (My_Decoder.value == 16773135){
       derecha();
            } else
    if (My_Decoder.value == 16769055){
       izquierda();
           }

  
  
   }
   
}

void adelante() // Ir adelante
{
    analogWrite(MOTOR1DE, velocidad);
    analogWrite(MOTOR1AT, 0);
    analogWrite(MOTOR2DE, velocidad);   
    analogWrite(MOTOR2AT, 0);
    
}
 
void atras() // Ir atras
{
    analogWrite(MOTOR1DE, 0);
    analogWrite(MOTOR1AT, velocidad);
    analogWrite(MOTOR2DE, 0);   
    analogWrite(MOTOR2AT, velocidad);
    
}
 
void derecha() // Ir a la derecha
{
    analogWrite(MOTOR1DE, 0);
    analogWrite(MOTOR1AT, velocidad);
    analogWrite(MOTOR2DE, velocidad);   
    analogWrite(MOTOR2AT, 0);
    
}
 
void izquierda() // Ir a la izquierda
{
    analogWrite(MOTOR1DE, velocidad);
    analogWrite(MOTOR1AT, 0);
    analogWrite(MOTOR2DE, 0);   
    analogWrite(MOTOR2AT, velocidad);
    
}
 
void parar() // Parar motores
{
    analogWrite(MOTOR1DE, 0);
    analogWrite(MOTOR1AT, 0);
    analogWrite(MOTOR2DE, 0);   
    analogWrite(MOTOR2AT, 0);
   
}
/* 
 * mando fino 
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
16746615   deln  */
