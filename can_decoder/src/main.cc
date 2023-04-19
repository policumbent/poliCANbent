#include <stdio.h>
#include "can_decoder.h"

int main() {
    CAN_Message msg(0b10001000000, 12593);
    char *topic, *payload;
    topic = msg.get_topic();
    payload = msg.get_payload();
    fprintf(stdout, "%s %s\n", topic, payload);

    return 0;
}