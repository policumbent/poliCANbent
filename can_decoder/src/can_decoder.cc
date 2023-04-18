#include "can_decoder.h"

CAN_Message::CAN_Message(int id, long long pl) {
    this->enc_id = id;
    this->enc_pl = pl;
}

int CAN_Message::get_type() {
    int type = this->enc_id >> 8;
    return type;
}

char *CAN_Message::get_topic() {
    int device = (this->enc_id & ID_DEV_MASK) >> 4;
    int specific = this->enc_id & ID_SPEC_MASK;

    char *topic;

    switch (device) {
        /*case (DEV_CORE_RPI):
            break;
        */

        case (DEV_GEARBOX):
            topic = get_gb_spec(specific);
            break;

        case (DEV_RPI_DATA):
            topic = get_rpi_spec(specific);
            break;

        case (DEV_GSM_DATA):
            topic = get_gsm_spec(specific);
            break;

        /*case (LOW_PRTY):
            break;
        */
    }

    return topic;
}

char *CAN_Message::get_payload() {

}

char *CAN_Message::get_gb_spec(int spec) {
    char *buf;

    switch (spec) {
        case (GB_LMT_SWITCH):
            buf = strdup("limit_switch");
            break;
        
        case (GB_RECEIVER):
            buf = strdup("cerberus_receiver");
            break;

        case (GB_GEARBOX):
            buf = strdup("gearbox");
            break;
        
        default:
            buf = strdup("unknown");
            break;
    }

    return buf;
}

char *CAN_Message::get_rpi_spec(int spec) {
    char *buf;

    switch (spec) {
        case (RPI_HS_SPEED):
            buf = strdup("hall_sensor_speed");
            break;

        case (RPI_HS_DISTANCE):
            buf = strdup("hall_sensor_distance");
            break;

        case (RPI_HS_W_RPM):
            buf = strdup("hall_sensor_wheel_rpm");
            break;

        case (RPI_SRM_PWR):
            buf = strdup("srm_power");
            break;

        case (RPI_SRM_P_RPM):
            buf = strdup("srm_pedal_rpm");
            break;

        case (RPI_HEART_RATE):
            buf = strdup("heart_rate");
            break;

        default:
            buf = strdup("unknown");
            break;
    }

    return buf;
}

char *CAN_Message::get_gsm_spec(int spec) {
    char *buf;

    switch (spec) {
        case (GSM_GPS_SPEED):
            buf = strdup("gps_speed");
            break;

        case (GSM_GPS_DIST):
            buf = strdup("gps_distance");
            break;

        default:
            buf = strdup("unknown");
            break;
    }

    return buf;
}