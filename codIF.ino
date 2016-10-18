#include <IRLib.h>

int RECV_PIN = 11;
int a=0;

IRrecv My_Receiver(RECV_PIN);

IRdecode My_Decoder;
unsigned int Buffer[RAWBUF];

void setup()
{
  Serial.begin(9600);
  //delay(2000);while(!Serial);//delay for Leonardo
  My_Receiver.enableIRIn(); // Start the receiver
  My_Decoder.UseExtnBuf(Buffer);
}

void loop() {
  if (My_Receiver.GetResults(&My_Decoder)) {
    //Restart the receiver so it can be capturing another code
    //while we are working on decoding this one.
    My_Receiver.resume(); 
    My_Decoder.decode();
    //My_Decoder.DumpResults();
    Serial.println(My_Decoder.value, HEX);
   
    
  }
   delay(1000);
}
/* 80BF49B6   1
   80BFC936   2
   80BF33CC   3
   80BF718E   4
   80BFF10E   5
   80BF13EC   6
   80BF51AE   7
   80BFD12E   8
   80BF23DC   9
   80BFE11E   0
   80BF53AC   UP
   80BF9966   IZ
   80BF837C   DR
   80BF4BB4   AB   */
