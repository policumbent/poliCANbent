#include <Arduino.h>
#include <esp32_can.h>


void printFrame(CAN_FRAME *message)
{
  Serial.print(message->id, HEX);
  if (message->extended) Serial.print(" X ");
  else Serial.print(" S ");   
  Serial.print(message->length, DEC);
  Serial.print(" ");
  for (int i = 0; i < message->length; i++) {
    Serial.print(message->data.byte[i], HEX);
    Serial.print(" ");
  }
  Serial.println();
}

void setup() {
    Serial.begin(9600);

    delay(5000);
    Serial.println("CAN sender");

    CAN0.setCANPins(GPIO_NUM_19, GPIO_NUM_18);
    while (!CAN0.begin(500000)) {
        Serial.println("CAN ERROR");
    }

    CAN0.watchFor();

    Serial.println("CAN OK");
}

void loop() {
    Serial.println("Another iteration");

    CAN_FRAME can_msg;
    if (CAN0.read(can_msg)) {
        Serial.println("arrived");
        printFrame(&can_msg);
    }

    Serial.println("Ready ...!");
    CAN_FRAME txFrame;
    txFrame.rtr = 0;
    txFrame.id = 0b10001000100;
    txFrame.extended = false;
    txFrame.length = 2;
    txFrame.data.uint8[0] = 0x28;
    txFrame.data.uint8[1] = 0x6B;
    CAN0.sendFrame(txFrame);

    delay(1000);
}
