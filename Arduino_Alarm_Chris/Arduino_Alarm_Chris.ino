void setup() {
  // put your setup code here, to run once:
  pinMode(3, INPUT); //PIR SENSOR INPUT
  pinMode(4, INPUT); //DISARM BUTTON INPUT
  pinMode(11, OUTPUT); //GREEN LED
  pinMode(12, OUTPUT); //RED LED
}

void loop() {
  // put your main code here, to run repeatedly:
  int armed=0;
  digitalWrite(11, HIGH);
  while(1){
    int alarm=1;
    if(digitalRead(3)==1 && armed==1){//if sensor is tripped and armed
      while(alarm){//while in the alarm state

        digitalWrite(11,LOW);//turns off green LED
        digitalWrite(12, HIGH);//flashes red LED on
        delay(100);//stop for .1s
        digitalWrite(12,LOW);//turns off 
        delay(100);//stop for .1s
        
        if(digitalRead(4)==1){//if disarm button pushed
          alarm=0;
          armed=0;
          digitalWrite(11,HIGH);//green LED on
          digitalWrite(12,LOW);//red LED off
          delay(2000);
        }
      }
    }
    else{//this is the armed state
        if(digitalRead(4)==1 && armed==0){//if disarmed and button is pushed, arm
          digitalWrite(11,LOW);//green LED off
          digitalWrite(12,HIGH);//red LED on
          armed=1;//set the armed state
          delay(200);//wait for .2 s
        }
        if(digitalRead(4)==1 && armed==1){//if armed and button is pushed
          digitalWrite(11,HIGH);//green LED on
          digitalWrite(12,LOW);//red LED off 
          armed=0;//disarm
          delay(200);
        }
    }
  }
}
