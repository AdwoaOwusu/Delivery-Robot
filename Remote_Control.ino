#define back_right 5
#define back_left 9
#define forward_right 3
#define forward_left 6
#define enA 11
#define enB 10

void setup_remote() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  pinMode(back_right, OUTPUT);
  pinMode(forward_right, OUTPUT);
  pinMode(back_left, OUTPUT);
  pinMode(forward_left, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);

  digitalWrite(enA, HIGH);
  digitalWrite(enB, HIGH);
}

void loop_remote() {
  
    if(IrReceiver.decode())
      {
         int results = IrReceiver.decodedIRData.command;
         Serial.println(results);

        if (results == 12)//Press FORWARD Button
        { 
          Forward();
        }
        else if (results == 24)//Press BACK Button
        { 
          Backward();
        }
         else if (results == 94)//Press LEFT Button
        { 
          Left();
        }
        else if (results == 8)//Press RIGHT Button
        { 
          Right();
        }
        else if (results  == 22)//Stop
        { 
          Stop();
        }
      IrReceiver.resume();
    }
   }
   
 
void Backward()
  {
  digitalWrite(back_right,HIGH);
  digitalWrite(forward_right,LOW);
  digitalWrite(back_left,HIGH);
  digitalWrite(forward_left,LOW);
  }

  
 void Forward(){
  digitalWrite(back_right,LOW);
  digitalWrite(forward_right,HIGH);
  digitalWrite(back_left,HIGH);
  digitalWrite(forward_left,LOW);
}

  
 void Stop(){
  digitalWrite(back_right,LOW);
  digitalWrite(forward_right,LOW);
  digitalWrite(back_left,LOW);
  digitalWrite(forward_left,LOW);
}

  
 void Left(){
    digitalWrite(back_right,LOW);
    digitalWrite(forward_right,LOW);
    digitalWrite(back_left,LOW);
    digitalWrite(forward_left,HIGH);
 }

    
 void Right(){
    digitalWrite(back_right,LOW);
    digitalWrite(forward_right,HIGH);
    digitalWrite(back_left,LOW);
    digitalWrite(forward_left,LOW);
}
