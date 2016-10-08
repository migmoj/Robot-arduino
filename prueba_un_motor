int MOTOR1IZ = 3;
int MOTOR1DE = 5;
int i=0;

void setup() {
  pinMode(MOTOR1IZ, OUTPUT);
  pinMode(MOTOR1DE, OUTPUT);
  Serial.begin (9600);
  analogWrite(MOTOR1IZ, 0);
  analogWrite(MOTOR1DE, 0);
}

void loop() {
 for (i=0; i<=255; i++){
  analogWrite(MOTOR1IZ, i);
  Serial.println(i);
  delay (200);
    }
 for (i=255; i>=0; i--){
  analogWrite(MOTOR1IZ, i);
  Serial.println(i);
  delay (200);
    }
 for (i=0; i<=255; i++){
  analogWrite(MOTOR1DE, i);
  Serial.println(i);
  delay (200);
    }
 for (i=255; i>=0; i--){
  analogWrite(MOTOR1DE, i);
  Serial.println(i);
  delay (200);
    }
}
