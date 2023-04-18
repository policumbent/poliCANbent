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
    char buf[25];

    switch (spec) {
        case (GB_LMT_SWITCH):
            sprintf(buf, "limit_switch");
            break;
        
        case (GB_RECEIVER):
            sprintf(buf, "cerberus_receiver");
            break;

        case (GB_GEARBOX):
            sprintf(buf, "gearbox");
            break;
        
        default:
            sprintf(buf, "unknown");
            break;
    }

    return buf;
}

char *CAN_Message::get_rpi_spec(int spec) {
    char buf[25];

    switch (spec) {
        case (RPI_HS_SPEED):
            sprintf(buf, "hall_sensor_speed");
            break;

        case (RPI_HS_DISTANCE):
            sprintf(buf, "hall_sensor_distance");
            break;

        case (RPI_HS_W_RPM):
            sprintf(buf, "hall_sensor_wheel_rpm");
            break;

        case (RPI_SRM_PWR):
            sprintf(buf, "srm_power");
            break;

        case (RPI_SRM_P_RPM):
            sprintf(buf, "srm_pedal_rpm");
            break;

        case (RPI_HEART_RATE):
            sprintf(buf, "heart_rate");
            break;

        default:
            sprintf(buf, "unknown");
            break;
    }

    return buf;
}

char *CAN_Message::get_gsm_spec(int spec) {
    char buf[25];

    switch (spec) {
        case (GSM_GPS_SPEED):
            sprintf(buf, "gps_speed");
            break;

        case (GSM_GPS_DIST):
            sprintf(buf, "gps_distance");
            break;

        default:
            sprintf(buf, "unknown");
            break;
    }

    return buf;
}