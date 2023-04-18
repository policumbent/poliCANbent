#include <stdio.h>

#define ID_TYPE_MASK 0b11100000000  // an 8-bit shift right can be used instead

#define ID_DEV_MASK  0b00011110000
#define ID_SPEC_MASK 0b00000001111

#define MSG_DEBUG 0
#define MSG_ERROR 1
#define MSG_DATA  2
#define MSG_INFO  3

#define DEV_CORE_RPI    0b0000
#define DEV_GEARBOX     0b0001
#define DEV_RPI_DATA    0b0010
#define DEV_GSM_DATA    0b0100
#define DEV_LOW_PRTY    0b1000

#define GB_LMT_SWITCH   0b0000
#define GB_RECEIVER     0b0001   // Cerberus only
#define GB_GEARBOX      0b0010

#define RPI_HS_SPEED    0b0000
#define RPI_HS_DISTANCE 0b0001
#define RPI_HS_W_RPM    0b0010
#define RPI_SRM_PWR     0b0100
#define RPI_SRM_P_RPM   0b0101
#define RPI_HEART_RATE  0b1100

#define GSM_GPS_SPEED  0b0000
#define GSM_GPS_DIST   0b0001
// #define GSM_GPS_COOR    0b0010

class CAN_Message {
    private:
        int enc_id;
        long long enc_pl;
        int type;
        char *topic;
        char *payload;

        char *get_gb_spec(int spec);
        char *get_rpi_spec(int spec);
        char *get_gsm_spec(int spec);

    public:
        /*
         * CAN_Message constructor
         * @param CAN message ID
         * @param CAN message encoded payload
         */
        CAN_Message(int id, long long pl);
        int get_type();
        char *get_topic();
        char *get_payload();
};