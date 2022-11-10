int PIR =3;

void setup() {
  pinMode(3, INPUT); //PIR SENSOR INPUT
  pinMode(4, INPUT); //DISARM BUTTON INPUT
  pinMode(11, OUTPUT); //GREEN LED
  pinMode(12, OUTPUT); //RED LED
}
void loop() {
  int armed=0;
  digitalWrite(11, HIGH);
  while(1){
    int alarm=1;
    if(digitalRead(3)==1 && armed==1){
      while(alarm){
        digitalWrite(11,LOW);
        digitalWrite(12, HIGH);
        delay(100);
        digitalWrite(12,LOW);
        delay(100);
        if(digitalRead(4)==1){
          alarm=0;
          armed=0;
          digitalWrite(11,HIGH);
          digitalWrite(12,LOW);
          delay(2000);
        }
      }
    }
    else{
        if(digitalRead(4)==1 && armed==0){
          digitalWrite(11,LOW);
          digitalWrite(12,HIGH);
          armed=1;
          delay(200);
        }
        if(digitalRead(4)==1 && armed==1){
          digitalWrite(11,HIGH);
          digitalWrite(12,LOW);
          armed=0;
          delay(200);
        }
    }
  }
}
