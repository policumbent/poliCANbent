#include <stdio.h>
#include <string.h>

#define ID_TYPE_MASK    0b11000000000  // not used

#define ID_DEV_MASK     0b00111100000
#define ID_SPEC_MASK    0b00000011111

#define MSG_DEBUG       0
#define MSG_ERROR       1
#define MSG_DATA        2
#define MSG_INFO        3

#define DEV_CORE_RPI    0b0000
#define DEV_GEARBOX     0b0001
#define DEV_RPI_DATA    0b0010
#define DEV_GSM_DATA    0b0100
#define DEV_LOW_PRTY    0b1000

#define GB_LMT_SWITCH   0b00000
#define GB_RECEIVER     0b00001   // Cerberus only
#define GB_GEARBOX      0b00010

#define RPI_HS_SPEED    0b00000
#define RPI_HS_DISTANCE 0b00001
#define RPI_HS_W_RPM    0b00010
#define RPI_SRM_PWR     0b00100
#define RPI_SRM_P_RPM   0b00101
#define RPI_HEART_RATE  0b01100

#define GSM_GPS_SPEED   0b00000
#define GSM_GPS_DIST    0b00001
// #define GSM_GPS_COOR     0b00010

#define DT_ERROR        1
#define DT_SPEED        2
#define DT_DISTANCE     3
#define DT_RPM          4
#define DT_POWER        5
#define DT_HEARTRATE    6
#define DT_GEAR         7

class CAN_Message {
    private:
        int enc_id;
        unsigned long long enc_pl;

        int data_type = 0;

        char *get_gb_spec(int spec);
        char *get_rpi_spec(int spec);
        char *get_gsm_spec(int spec);

        void get_type();

        char *get_speed();
        char *get_distance();
        char *get_rpm();
        char *get_power();
        char *get_heart_rate();
        char *get_gear();

    public:
        /*
         * CAN_Message constructor
         * @param id: CAN message ID
         * @param pl: CAN message encoded payload
         */
        CAN_Message(int id, unsigned long long pl);
        /*
         * @return char*: string representing the MQTT topic
         */
        char *get_topic();
        /*
         * @return char*: string representing the value of the corresponding
         * message topic
         */
        char *get_payload();
};