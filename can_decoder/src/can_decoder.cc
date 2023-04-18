#include "can_decoder.h"

CAN_Message::CAN_Message(int id, long long pl) {
    this->enc_id = id;
    this->enc_pl = pl;
}

int CAN_Message::get_type() {

}

char *CAN_Message::get_topic() {

}

char *CAN_Message::get_payload() {

}