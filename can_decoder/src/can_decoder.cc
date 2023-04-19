#include "can_decoder.h"

CAN_Message::CAN_Message(int id, unsigned long long pl) {
    this->enc_id = id;
    this->enc_pl = pl;
}

void CAN_Message::get_type() {
    int type = this->enc_id >> 9;

    if (type == MSG_ERROR) {
        this->data_type = DT_ERROR;
    }

    return;
}

char *CAN_Message::get_topic() {
    get_type();

    int device = (this->enc_id & ID_DEV_MASK) >> 5;
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
    char *buf;

    switch (this->data_type) {
        case (DT_ERROR):
            buf = strdup("error");
            break;

        case (DT_SPEED):
            buf = get_speed();
            break;

        case (DT_DISTANCE):
            buf = get_distance();
            break;

        case (DT_RPM):
            buf = get_rpm();
            break;

        case (DT_POWER):
            buf = get_power();
            break;

        case (DT_HEARTRATE):
            buf = get_heart_rate();
            break;

        case (DT_GEAR):
            buf = get_gear();
            break;

        default:
            buf = strdup("unknown");
    }

    return buf;
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

            if (!this->data_type) {
                this->data_type = DT_GEAR;
            }

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

            if (!this->data_type) {
                this->data_type = DT_SPEED;
            }

            break;

        case (RPI_HS_DISTANCE):
            buf = strdup("hall_sensor_distance");

            if (!this->data_type) {
                this->data_type = DT_DISTANCE;
            }

            break;

        case (RPI_HS_W_RPM):
            buf = strdup("hall_sensor_wheel_rpm");

            if (!this->data_type) {
                this->data_type = DT_RPM;
            }

            break;

        case (RPI_SRM_PWR):
            buf = strdup("srm_power");

            if (!this->data_type) {
                this->data_type = DT_POWER;
            }

            break;

        case (RPI_SRM_P_RPM):
            buf = strdup("srm_pedal_rpm");

            if (!this->data_type) {
                this->data_type = DT_DISTANCE;
            }

            break;

        case (RPI_HEART_RATE):
            buf = strdup("heart_rate");

            if (!this->data_type) {
                this->data_type = DT_HEARTRATE;
            }

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

            if (!this->data_type) {
                this->data_type = DT_SPEED;
            }

            break;

        case (GSM_GPS_DIST):
            buf = strdup("gps_distance");

            if (!this->data_type) {
                this->data_type = DT_DISTANCE;
            }

            break;

        default:
            buf = strdup("unknown");
            break;
    }

    return buf;
}

char *CAN_Message::get_speed() {
    char buf[10];
    char *returning;

    float speed = (float)this->enc_pl / 100;
    sprintf(buf, "%.2f", speed);
    returning = strdup(buf);

    return returning;
}

char *CAN_Message::get_distance() {
    char buf[10];
    char *returning;

    int distance = this->enc_pl;
    sprintf(buf, "%d", distance);
    returning = strdup(buf);

    return returning;
}

char *CAN_Message::get_rpm() {
    char buf[10];
    char *returning;

    float rpm = (float)this->enc_pl / 10;
    sprintf(buf, "%.1f", rpm);
    returning = strdup(buf);

    return returning;
}

char *CAN_Message::get_power() {
    char buf[10];
    char *returning;

    float power = (float)this->enc_pl / 10;
    sprintf(buf, "%.1f", power);
    returning = strdup(buf);

    return returning;
}

char *CAN_Message::get_heart_rate() {
    char buf[10];
    char *returning;

    int heart_rate = this->enc_pl;
    sprintf(buf, "%d", heart_rate);
    returning = strdup(buf);

    return returning;
}

char *CAN_Message::get_gear() {
    char buf[10];
    char *returning;

    int gear = this->enc_pl;
    sprintf(buf, "%d", gear);
    returning = strdup(buf);

    return returning;
}