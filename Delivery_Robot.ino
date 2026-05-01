#include<IRremote.hpp>

#define IR_RECEIVE_PIN 8

void setup(){
  setup_remote();
}

void loop(){
  loop_remote();
}


//
//#include <IRremote.hpp>
//#define IR_RECEIVE_PIN 8
//
//void setup() {
//  Serial.begin(9600);
//  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
//  setup_remote();
//}
//
//void loop() {
//  loop_remote();
//}
