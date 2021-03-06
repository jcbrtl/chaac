#ifndef __CHAAC_PACKET_H__
#define __CHAAC_PACKET_H__

// Note, if you update this, make sure to update the corresponding
// definitoins in sw/chaac/chaac/packets.py
typedef enum {
    PACKET_TYPE_DATA = 1,
    PACKET_TYPE_GPS = 2,
    PACKET_TYPE_BOOT = 3,
    PACKET_TYPE_CLEAR_RAIN = 4,
} packet_type_t;

typedef struct {
    uint32_t    uid;
    uint8_t     type;
} __attribute__ ((packed)) chaac_header_t;

typedef struct {
    chaac_header_t  header;
    uint32_t        sample;
    float           wind_speed;
    float           wind_dir;
    float           rain;
    float           temperature;
    float           humidity;
    float           temperature_in;
    float           pressure;
    float           light;
    float           battery;
    float           solar_panel;
} __attribute__((packed)) weather_data_packet_t;

typedef struct {
    uint8_t     sample;
    uint8_t     wind_dir;
    uint8_t     rain;
    uint8_t     rsvd;
    uint16_t    wind_speed;
    int16_t     temperature;
    uint16_t    humidity;
    int16_t    pressure;
    uint16_t    battery;
    uint16_t    solar_panel;
} __attribute__((packed)) weather_data_packet_small_t;

// TODO
typedef struct {
    chaac_header_t  header;
    int32_t         lat_degrees;
    double          lat_minutes;
    char            lat_cardinal;
    int32_t         lon_degrees;
    double          lon_minutes;
    char            lon_cardinal;
} __attribute__((packed)) weather_gps_packet_t;

typedef struct {
    chaac_header_t  header;
    uint8_t         flags;
} __attribute__((packed)) boot_packet_t;

typedef struct {
    chaac_header_t  header;
    uint8_t         flags;
} __attribute__((packed)) clear_rain_packet_t;

#endif
