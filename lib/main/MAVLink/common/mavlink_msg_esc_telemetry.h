// MESSAGE ESC_TELEMETRY PACKING

#define MAVLINK_MSG_ID_ESC_TELEMETRY 199

typedef struct __mavlink_esc_telemetry_t
{
    uint32_t current[4];     ///< ESC current, in centiamperes (1 = 0.01 ampere)
    uint32_t totalcurrent[4]; ///< Total current consumption, in milliampere-hours (mAh)
    uint16_t voltage[4];     ///< ESC voltage, in centivolts (1 = 0.01 volt)
    uint16_t rpm[4];         ///< Motor RPM (electrical RPM)
  	uint8_t temperature[4];  ///< ESC temperature, in degrees Celsius
} mavlink_esc_telemetry_t;

#define MAVLINK_MSG_ID_ESC_TELEMETRY_LEN 52
#define MAVLINK_MSG_ID_169_LEN 52

#define MAVLINK_MSG_ID_ESC_TELEMETRY_CRC 108
#define MAVLINK_MSG_ID_169_CRC 108

/**
 * @brief Pack a esc_telemetry message
 * @param system_id ID of this system
 * @param component_id ID of this component
 * @param msg The MAVLink message to compress the data into
 */
static inline uint16_t mavlink_msg_esc_telemetry_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                                                      const uint32_t* current, const uint32_t* totalcurrent,
                                                      const uint16_t* voltage, const uint16_t* rpm,
                                                      const uint8_t* temperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
  	#pragma message("MAVLINK_NEED_BYTE_SWAP or !MAVLINK_ALIGNED_FIELDS")
    char buf[MAVLINK_MSG_ID_ESC_TELEMETRY_LEN];

    _mav_put_uint32_t_array(buf, 0, current, 4);
    _mav_put_uint32_t_array(buf, 16, totalcurrent, 4);
    _mav_put_uint16_t_array(buf, 32, voltage, 4);
    _mav_put_uint16_t_array(buf, 40, rpm, 4);
    _mav_put_uint8_t_array(buf, 48, temperature, 4);

    memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ESC_TELEMETRY_LEN);
#else
  	#pragma message("Easy case") // No need to worry about ordering here; defined at the top in the struct
    mavlink_esc_telemetry_t packet;

    memcpy(packet.current, current, sizeof(packet.current));
    memcpy(packet.totalcurrent, totalcurrent, sizeof(packet.totalcurrent));
    memcpy(packet.voltage, voltage, sizeof(packet.voltage));
    memcpy(packet.rpm, rpm, sizeof(packet.rpm));
    memcpy(packet.temperature, temperature, sizeof(packet.temperature));

    memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ESC_TELEMETRY_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ESC_TELEMETRY;
#if MAVLINK_CRC_EXTRA
    #pragma message("MAVLINK_CRC_EXTRA")
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ESC_TELEMETRY_LEN, MAVLINK_MSG_ID_ESC_TELEMETRY_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ESC_TELEMETRY_LEN);
#endif
}

/**
 * @brief Pack a esc_telemetry message on a channel
 */
static inline uint16_t mavlink_msg_esc_telemetry_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                                                           mavlink_message_t* msg,
                                                           const uint16_t* current, const uint16_t* totalcurrent,
                                                           const uint16_t* voltage, const uint16_t* rpm,
                                                           const uint8_t* temperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ESC_TELEMETRY_LEN];

    _mav_put_uint32_t_array(buf, 0, current, 4);
    _mav_put_uint32_t_array(buf, 16, totalcurrent, 4);
    _mav_put_uint16_t_array(buf, 32, voltage, 4);
    _mav_put_uint16_t_array(buf, 40, rpm, 4);
    _mav_put_uint8_t_array(buf, 48, temperature, 4);

    memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ESC_TELEMETRY_LEN);
#else
    mavlink_esc_telemetry_t packet;
    memcpy(packet.voltage, voltage, sizeof(packet.voltage));
    memcpy(packet.current, current, sizeof(packet.current));
    memcpy(packet.totalcurrent, totalcurrent, sizeof(packet.totalcurrent));
    memcpy(packet.rpm, rpm, sizeof(packet.rpm));
    memcpy(packet.temperature, temperature, sizeof(packet.temperature));

    memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ESC_TELEMETRY_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ESC_TELEMETRY;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ESC_TELEMETRY_LEN, MAVLINK_MSG_ID_ESC_TELEMETRY_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ESC_TELEMETRY_LEN);
#endif
}