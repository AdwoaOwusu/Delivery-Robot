#include <Servo.h>

#define back_right 5
#define back_left 9
#define forward_right 3
#define forward_left 6
#define enA 11
#define enB 10
#define shoulder 7
#define gripper 4 
#define elbow 12 

Servo shoulderServo;
int shoulderIntPos = 140;

Servo gripperServo; 
int gripperIntPos = 0;

Servo elbowServo; 
int elbowIntPos = 100;

void setup_remote() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  pinMode(back_right, OUTPUT);
  pinMode(forward_right, OUTPUT);
  pinMode(back_left, OUTPUT);
  pinMode(forward_left, OUTPUT);
  
  pinMode(shoulder, OUTPUT);
  shoulderServo.write(shoulderIntPos);
  shoulderServo.attach(shoulder);
  
  pinMode(gripper, OUTPUT);
  gripperServo.write(gripperIntPos);
  gripperServo.attach(gripper);
    
  pinMode(elbow, OUTPUT);
  elbowServo.write(elbowIntPos);
  elbowServo.attach(elbow);

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
        else if (results == 28)
        {
          ShoulderDown();
        }
        else if (results == 90)
        {
          ShoulderUp();
        }
         else if (results == 66)
        {
          ElbowUp();
        }
        else if (results == 82)
        {
          ElbowDown();
        }
        else if (results == 9)
        {
          GripperOpen();
        }
        else if (results == 21)
        {
          GripperClose();
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

void ShoulderDown(){
   shoulderIntPos = min(shoulderIntPos + 10, 180);
   shoulderServo.write(shoulderIntPos);
   delay(30);
}

void ShoulderUp(){
   shoulderIntPos = max(shoulderIntPos - 10, 0);
   shoulderServo.write(shoulderIntPos);
   delay(30);
}

void ElbowUp(){
   elbowIntPos = min(elbowIntPos + 10, 180);
   elbowServo.write(elbowIntPos);
   delay(30);
}

void ElbowDown(){
   elbowIntPos = max(elbowIntPos - 10, 0);
   elbowServo.write(elbowIntPos);
   delay(30);
}

void GripperOpen(){
   gripperIntPos = min(gripperIntPos + 50, 180);
   gripperServo.write(gripperIntPos);
   delay(30);
}

void GripperClose(){
   gripperIntPos = max(gripperIntPos - 50, 0);
   gripperServo.write(gripperIntPos);
   delay(30);
}
