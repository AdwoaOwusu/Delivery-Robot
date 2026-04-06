#include<IRremote.hpp>

#define IR_RECEIVE_PIN 8
#define RemotePin 8


IRrecv irrecv(RemotePin);

void setup(){
  setup_main();
  setup_remote();
}

void loop(){
  loop_main();
  loop_remote();
}

void setup_main() {
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop_main() {
  if(IrReceiver.decode())
  {
    delay(200);
    irrecv.resume();
  }
}
