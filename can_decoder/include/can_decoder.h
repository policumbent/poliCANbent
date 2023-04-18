#define ID_TYPE_MASK 0b11100000000
#define ID_DEV_MASK  0b00011110000
#define ID_SPEC_MASK 0b00000001111

#define MSG_DEBUG 0
#define MSG_ERROR 1
#define MSG_DATA  2
#define MSG_INFO  3

class CAN_Message {
    private:
        int enc_id;
        long long enc_pl;
        int type;
        char *topic;
        char *payload;

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