/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2018-2019 Erik Moqvist
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/**
 * This file was generated by cantools version 39.4.5 Sun May 26 20:55:27 2024.
 */

#include <string.h>

#include "policanbent.h"

static inline uint8_t pack_left_shift_u8(
    uint8_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint8_t)((uint8_t)(value << shift) & mask);
}

static inline uint8_t pack_left_shift_u16(
    uint16_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint8_t)((uint8_t)(value << shift) & mask);
}

static inline uint8_t pack_left_shift_u32(
    uint32_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint8_t)((uint8_t)(value << shift) & mask);
}

static inline uint8_t pack_right_shift_u16(
    uint16_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint8_t)((uint8_t)(value >> shift) & mask);
}

static inline uint8_t pack_right_shift_u32(
    uint32_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint8_t)((uint8_t)(value >> shift) & mask);
}

static inline uint16_t unpack_left_shift_u16(
    uint8_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint16_t)((uint16_t)(value & mask) << shift);
}

static inline uint32_t unpack_left_shift_u32(
    uint8_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint32_t)((uint32_t)(value & mask) << shift);
}

static inline uint8_t unpack_right_shift_u8(
    uint8_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint8_t)((uint8_t)(value & mask) >> shift);
}

static inline uint16_t unpack_right_shift_u16(
    uint8_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint16_t)((uint16_t)(value & mask) >> shift);
}

static inline uint32_t unpack_right_shift_u32(
    uint8_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint32_t)((uint32_t)(value & mask) >> shift);
}

int policanbent_gb_error_pack(
    uint8_t *dst_p,
    const struct policanbent_gb_error_t *src_p,
    size_t size)
{
    if (size < 1u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 1);

    dst_p[0] |= pack_left_shift_u8(src_p->gb_err_code, 0u, 0x07u);
    dst_p[0] |= pack_left_shift_u8(src_p->gb_gear, 3u, 0xf8u);

    return (1);
}

int policanbent_gb_error_unpack(
    struct policanbent_gb_error_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 1u) {
        return (-EINVAL);
    }

    dst_p->gb_err_code = unpack_right_shift_u8(src_p[0], 0u, 0x07u);
    dst_p->gb_gear = unpack_right_shift_u8(src_p[0], 3u, 0xf8u);

    return (0);
}

int policanbent_gb_error_init(struct policanbent_gb_error_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct policanbent_gb_error_t));

    return 0;
}

uint8_t policanbent_gb_error_gb_err_code_encode(double value)
{
    return (uint8_t)(value);
}

double policanbent_gb_error_gb_err_code_decode(uint8_t value)
{
    return ((double)value);
}

bool policanbent_gb_error_gb_err_code_is_in_range(uint8_t value)
{
    return (value <= 7u);
}

uint8_t policanbent_gb_error_gb_gear_encode(double value)
{
    return (uint8_t)(value);
}

double policanbent_gb_error_gb_gear_decode(uint8_t value)
{
    return ((double)value);
}

bool policanbent_gb_error_gb_gear_is_in_range(uint8_t value)
{
    return (value <= 16u);
}

int policanbent_gb_data_pack(
    uint8_t *dst_p,
    const struct policanbent_gb_data_t *src_p,
    size_t size)
{
    if (size < 1u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 1);

    dst_p[0] |= pack_left_shift_u8(src_p->gb_gear, 0u, 0x1fu);

    return (1);
}

int policanbent_gb_data_unpack(
    struct policanbent_gb_data_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 1u) {
        return (-EINVAL);
    }

    dst_p->gb_gear = unpack_right_shift_u8(src_p[0], 0u, 0x1fu);

    return (0);
}

int policanbent_gb_data_init(struct policanbent_gb_data_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct policanbent_gb_data_t));

    return 0;
}

uint8_t policanbent_gb_data_gb_gear_encode(double value)
{
    return (uint8_t)(value);
}

double policanbent_gb_data_gb_gear_decode(uint8_t value)
{
    return ((double)value);
}

bool policanbent_gb_data_gb_gear_is_in_range(uint8_t value)
{
    return (value <= 16u);
}

int policanbent_greta_data_pack(
    uint8_t *dst_p,
    const struct policanbent_greta_data_t *src_p,
    size_t size)
{
    if (size < 2u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 2);

    dst_p[0] |= pack_left_shift_u8(src_p->telek_battery, 0u, 0x7fu);
    dst_p[1] |= pack_left_shift_u8(src_p->rx_shifting, 0u, 0x03u);

    return (2);
}

int policanbent_greta_data_unpack(
    struct policanbent_greta_data_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 2u) {
        return (-EINVAL);
    }

    dst_p->telek_battery = unpack_right_shift_u8(src_p[0], 0u, 0x7fu);
    dst_p->rx_shifting = unpack_right_shift_u8(src_p[1], 0u, 0x03u);

    return (0);
}

int policanbent_greta_data_init(struct policanbent_greta_data_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct policanbent_greta_data_t));

    return 0;
}

uint8_t policanbent_greta_data_telek_battery_encode(double value)
{
    return (uint8_t)(value);
}

double policanbent_greta_data_telek_battery_decode(uint8_t value)
{
    return ((double)value);
}

bool policanbent_greta_data_telek_battery_is_in_range(uint8_t value)
{
    return (value <= 100u);
}

uint8_t policanbent_greta_data_rx_shifting_encode(double value)
{
    return (uint8_t)(value);
}

double policanbent_greta_data_rx_shifting_decode(uint8_t value)
{
    return ((double)value);
}

bool policanbent_greta_data_rx_shifting_is_in_range(uint8_t value)
{
    return (value <= 3u);
}

int policanbent_bob_srm_power_pack(
    uint8_t *dst_p,
    const struct policanbent_bob_srm_power_t *src_p,
    size_t size)
{
    if (size < 2u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 2);

    dst_p[0] |= pack_left_shift_u16(src_p->srm_power, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(src_p->srm_power, 8u, 0xffu);

    return (2);
}

int policanbent_bob_srm_power_unpack(
    struct policanbent_bob_srm_power_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 2u) {
        return (-EINVAL);
    }

    dst_p->srm_power = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    dst_p->srm_power |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);

    return (0);
}

int policanbent_bob_srm_power_init(struct policanbent_bob_srm_power_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct policanbent_bob_srm_power_t));

    return 0;
}

uint16_t policanbent_bob_srm_power_srm_power_encode(double value)
{
    return (uint16_t)(value / 0.1);
}

double policanbent_bob_srm_power_srm_power_decode(uint16_t value)
{
    return ((double)value * 0.1);
}

bool policanbent_bob_srm_power_srm_power_is_in_range(uint16_t value)
{
    return (value <= 10000u);
}

int policanbent_bob_srm_cadence_pack(
    uint8_t *dst_p,
    const struct policanbent_bob_srm_cadence_t *src_p,
    size_t size)
{
    if (size < 2u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 2);

    dst_p[0] |= pack_left_shift_u16(src_p->srm_cadence, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(src_p->srm_cadence, 8u, 0xffu);

    return (2);
}

int policanbent_bob_srm_cadence_unpack(
    struct policanbent_bob_srm_cadence_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 2u) {
        return (-EINVAL);
    }

    dst_p->srm_cadence = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    dst_p->srm_cadence |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);

    return (0);
}

int policanbent_bob_srm_cadence_init(struct policanbent_bob_srm_cadence_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct policanbent_bob_srm_cadence_t));

    return 0;
}

uint16_t policanbent_bob_srm_cadence_srm_cadence_encode(double value)
{
    return (uint16_t)(value / 0.1);
}

double policanbent_bob_srm_cadence_srm_cadence_decode(uint16_t value)
{
    return ((double)value * 0.1);
}

bool policanbent_bob_srm_cadence_srm_cadence_is_in_range(uint16_t value)
{
    return (value <= 10000u);
}

int policanbent_bob_hs_speed_pack(
    uint8_t *dst_p,
    const struct policanbent_bob_hs_speed_t *src_p,
    size_t size)
{
    if (size < 2u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 2);

    dst_p[0] |= pack_left_shift_u16(src_p->hs_speed, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(src_p->hs_speed, 8u, 0xffu);

    return (2);
}

int policanbent_bob_hs_speed_unpack(
    struct policanbent_bob_hs_speed_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 2u) {
        return (-EINVAL);
    }

    dst_p->hs_speed = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    dst_p->hs_speed |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);

    return (0);
}

int policanbent_bob_hs_speed_init(struct policanbent_bob_hs_speed_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct policanbent_bob_hs_speed_t));

    return 0;
}

uint16_t policanbent_bob_hs_speed_hs_speed_encode(double value)
{
    return (uint16_t)(value / 0.01);
}

double policanbent_bob_hs_speed_hs_speed_decode(uint16_t value)
{
    return ((double)value * 0.01);
}

bool policanbent_bob_hs_speed_hs_speed_is_in_range(uint16_t value)
{
    return (value <= 20000u);
}

int policanbent_bob_hs_displacement_pack(
    uint8_t *dst_p,
    const struct policanbent_bob_hs_displacement_t *src_p,
    size_t size)
{
    if (size < 2u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 2);

    dst_p[0] |= pack_left_shift_u16(src_p->hs_displacement, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(src_p->hs_displacement, 8u, 0xffu);

    return (2);
}

int policanbent_bob_hs_displacement_unpack(
    struct policanbent_bob_hs_displacement_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 2u) {
        return (-EINVAL);
    }

    dst_p->hs_displacement = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    dst_p->hs_displacement |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);

    return (0);
}

int policanbent_bob_hs_displacement_init(struct policanbent_bob_hs_displacement_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct policanbent_bob_hs_displacement_t));

    return 0;
}

uint16_t policanbent_bob_hs_displacement_hs_displacement_encode(double value)
{
    return (uint16_t)(value / 0.1);
}

double policanbent_bob_hs_displacement_hs_displacement_decode(uint16_t value)
{
    return ((double)value * 0.1);
}

bool policanbent_bob_hs_displacement_hs_displacement_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

int policanbent_bob_hr_pack(
    uint8_t *dst_p,
    const struct policanbent_bob_hr_t *src_p,
    size_t size)
{
    if (size < 1u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 1);

    dst_p[0] |= pack_left_shift_u8(src_p->heart_rate, 0u, 0xffu);

    return (1);
}

int policanbent_bob_hr_unpack(
    struct policanbent_bob_hr_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 1u) {
        return (-EINVAL);
    }

    dst_p->heart_rate = unpack_right_shift_u8(src_p[0], 0u, 0xffu);

    return (0);
}

int policanbent_bob_hr_init(struct policanbent_bob_hr_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct policanbent_bob_hr_t));

    return 0;
}

uint8_t policanbent_bob_hr_heart_rate_encode(double value)
{
    return (uint8_t)(value);
}

double policanbent_bob_hr_heart_rate_decode(uint8_t value)
{
    return ((double)value);
}

bool policanbent_bob_hr_heart_rate_is_in_range(uint8_t value)
{
    return (value <= 250u);
}

int policanbent_greta_error_pack(
    uint8_t *dst_p,
    const struct policanbent_greta_error_t *src_p,
    size_t size)
{
    if (size < 1u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 1);

    dst_p[0] |= pack_left_shift_u8(src_p->time_out_error, 0u, 0x01u);

    return (1);
}

int policanbent_greta_error_unpack(
    struct policanbent_greta_error_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 1u) {
        return (-EINVAL);
    }

    dst_p->time_out_error = unpack_right_shift_u8(src_p[0], 0u, 0x01u);

    return (0);
}

int policanbent_greta_error_init(struct policanbent_greta_error_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct policanbent_greta_error_t));

    return 0;
}

uint8_t policanbent_greta_error_time_out_error_encode(double value)
{
    return (uint8_t)(value);
}

double policanbent_greta_error_time_out_error_decode(uint8_t value)
{
    return ((double)value);
}

bool policanbent_greta_error_time_out_error_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

int policanbent_whereami_data_pack(
    uint8_t *dst_p,
    const struct policanbent_whereami_data_t *src_p,
    size_t size)
{
    if (size < 4u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 4);

    dst_p[0] |= pack_left_shift_u16(src_p->speed, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(src_p->speed, 8u, 0xffu);
    dst_p[2] |= pack_left_shift_u16(src_p->distance, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(src_p->distance, 8u, 0xffu);

    return (4);
}

int policanbent_whereami_data_unpack(
    struct policanbent_whereami_data_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 4u) {
        return (-EINVAL);
    }

    dst_p->speed = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    dst_p->speed |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->distance = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    dst_p->distance |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);

    return (0);
}

int policanbent_whereami_data_init(struct policanbent_whereami_data_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct policanbent_whereami_data_t));

    return 0;
}

uint16_t policanbent_whereami_data_speed_encode(double value)
{
    return (uint16_t)(value / 0.01);
}

double policanbent_whereami_data_speed_decode(uint16_t value)
{
    return ((double)value * 0.01);
}

bool policanbent_whereami_data_speed_is_in_range(uint16_t value)
{
    return (value <= 20000u);
}

uint16_t policanbent_whereami_data_distance_encode(double value)
{
    return (uint16_t)(value);
}

double policanbent_whereami_data_distance_decode(uint16_t value)
{
    return ((double)value);
}

bool policanbent_whereami_data_distance_is_in_range(uint16_t value)
{
    return (value <= 20000u);
}

int policanbent_whereami_coords_pack(
    uint8_t *dst_p,
    const struct policanbent_whereami_coords_t *src_p,
    size_t size)
{
    uint32_t latitude;
    uint32_t longitude;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    latitude = (uint32_t)src_p->latitude;
    dst_p[0] |= pack_left_shift_u32(latitude, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u32(latitude, 8u, 0xffu);
    dst_p[2] |= pack_right_shift_u32(latitude, 16u, 0xffu);
    dst_p[3] |= pack_right_shift_u32(latitude, 24u, 0xffu);
    longitude = (uint32_t)src_p->longitude;
    dst_p[4] |= pack_left_shift_u32(longitude, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u32(longitude, 8u, 0xffu);
    dst_p[6] |= pack_right_shift_u32(longitude, 16u, 0xffu);
    dst_p[7] |= pack_right_shift_u32(longitude, 24u, 0xffu);

    return (8);
}

int policanbent_whereami_coords_unpack(
    struct policanbent_whereami_coords_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint32_t latitude;
    uint32_t longitude;

    if (size < 8u) {
        return (-EINVAL);
    }

    latitude = unpack_right_shift_u32(src_p[0], 0u, 0xffu);
    latitude |= unpack_left_shift_u32(src_p[1], 8u, 0xffu);
    latitude |= unpack_left_shift_u32(src_p[2], 16u, 0xffu);
    latitude |= unpack_left_shift_u32(src_p[3], 24u, 0xffu);
    dst_p->latitude = (int32_t)latitude;
    longitude = unpack_right_shift_u32(src_p[4], 0u, 0xffu);
    longitude |= unpack_left_shift_u32(src_p[5], 8u, 0xffu);
    longitude |= unpack_left_shift_u32(src_p[6], 16u, 0xffu);
    longitude |= unpack_left_shift_u32(src_p[7], 24u, 0xffu);
    dst_p->longitude = (int32_t)longitude;

    return (0);
}

int policanbent_whereami_coords_init(struct policanbent_whereami_coords_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct policanbent_whereami_coords_t));

    return 0;
}

int32_t policanbent_whereami_coords_latitude_encode(double value)
{
    return (int32_t)(value / 1e-06);
}

double policanbent_whereami_coords_latitude_decode(int32_t value)
{
    return ((double)value * 1e-06);
}

bool policanbent_whereami_coords_latitude_is_in_range(int32_t value)
{
    return ((value >= -90000000) && (value <= 90000000));
}

int32_t policanbent_whereami_coords_longitude_encode(double value)
{
    return (int32_t)(value / 1e-06);
}

double policanbent_whereami_coords_longitude_decode(int32_t value)
{
    return ((double)value * 1e-06);
}

bool policanbent_whereami_coords_longitude_is_in_range(int32_t value)
{
    return ((value >= -180000000) && (value <= 180000000));
}

int policanbent_dumbms1_error_pack(
    uint8_t *dst_p,
    const struct policanbent_dumbms1_error_t *src_p,
    size_t size)
{
    if (size < 1u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 1);

    dst_p[0] |= pack_left_shift_u8(src_p->bat0_under_volt, 0u, 0x01u);
    dst_p[0] |= pack_left_shift_u8(src_p->bat1_under_volt, 1u, 0x02u);
    dst_p[0] |= pack_left_shift_u8(src_p->bat2_under_volt, 2u, 0x04u);
    dst_p[0] |= pack_left_shift_u8(src_p->bat3_under_volt, 3u, 0x08u);
    dst_p[0] |= pack_left_shift_u8(src_p->bat4_under_volt, 4u, 0x10u);

    return (1);
}

int policanbent_dumbms1_error_unpack(
    struct policanbent_dumbms1_error_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 1u) {
        return (-EINVAL);
    }

    dst_p->bat0_under_volt = unpack_right_shift_u8(src_p[0], 0u, 0x01u);
    dst_p->bat1_under_volt = unpack_right_shift_u8(src_p[0], 1u, 0x02u);
    dst_p->bat2_under_volt = unpack_right_shift_u8(src_p[0], 2u, 0x04u);
    dst_p->bat3_under_volt = unpack_right_shift_u8(src_p[0], 3u, 0x08u);
    dst_p->bat4_under_volt = unpack_right_shift_u8(src_p[0], 4u, 0x10u);

    return (0);
}

int policanbent_dumbms1_error_init(struct policanbent_dumbms1_error_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct policanbent_dumbms1_error_t));

    return 0;
}

uint8_t policanbent_dumbms1_error_bat0_under_volt_encode(double value)
{
    return (uint8_t)(value);
}

double policanbent_dumbms1_error_bat0_under_volt_decode(uint8_t value)
{
    return ((double)value);
}

bool policanbent_dumbms1_error_bat0_under_volt_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t policanbent_dumbms1_error_bat1_under_volt_encode(double value)
{
    return (uint8_t)(value);
}

double policanbent_dumbms1_error_bat1_under_volt_decode(uint8_t value)
{
    return ((double)value);
}

bool policanbent_dumbms1_error_bat1_under_volt_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t policanbent_dumbms1_error_bat2_under_volt_encode(double value)
{
    return (uint8_t)(value);
}

double policanbent_dumbms1_error_bat2_under_volt_decode(uint8_t value)
{
    return ((double)value);
}

bool policanbent_dumbms1_error_bat2_under_volt_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t policanbent_dumbms1_error_bat3_under_volt_encode(double value)
{
    return (uint8_t)(value);
}

double policanbent_dumbms1_error_bat3_under_volt_decode(uint8_t value)
{
    return ((double)value);
}

bool policanbent_dumbms1_error_bat3_under_volt_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t policanbent_dumbms1_error_bat4_under_volt_encode(double value)
{
    return (uint8_t)(value);
}

double policanbent_dumbms1_error_bat4_under_volt_decode(uint8_t value)
{
    return ((double)value);
}

bool policanbent_dumbms1_error_bat4_under_volt_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

int policanbent_dumbms2_error_pack(
    uint8_t *dst_p,
    const struct policanbent_dumbms2_error_t *src_p,
    size_t size)
{
    if (size < 1u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 1);

    dst_p[0] |= pack_left_shift_u8(src_p->bat0_under_volt, 0u, 0x01u);
    dst_p[0] |= pack_left_shift_u8(src_p->bat1_under_volt, 1u, 0x02u);
    dst_p[0] |= pack_left_shift_u8(src_p->bat2_under_volt, 2u, 0x04u);
    dst_p[0] |= pack_left_shift_u8(src_p->bat3_under_volt, 3u, 0x08u);
    dst_p[0] |= pack_left_shift_u8(src_p->bat4_under_volt, 4u, 0x10u);

    return (1);
}

int policanbent_dumbms2_error_unpack(
    struct policanbent_dumbms2_error_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 1u) {
        return (-EINVAL);
    }

    dst_p->bat0_under_volt = unpack_right_shift_u8(src_p[0], 0u, 0x01u);
    dst_p->bat1_under_volt = unpack_right_shift_u8(src_p[0], 1u, 0x02u);
    dst_p->bat2_under_volt = unpack_right_shift_u8(src_p[0], 2u, 0x04u);
    dst_p->bat3_under_volt = unpack_right_shift_u8(src_p[0], 3u, 0x08u);
    dst_p->bat4_under_volt = unpack_right_shift_u8(src_p[0], 4u, 0x10u);

    return (0);
}

int policanbent_dumbms2_error_init(struct policanbent_dumbms2_error_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct policanbent_dumbms2_error_t));

    return 0;
}

uint8_t policanbent_dumbms2_error_bat0_under_volt_encode(double value)
{
    return (uint8_t)(value);
}

double policanbent_dumbms2_error_bat0_under_volt_decode(uint8_t value)
{
    return ((double)value);
}

bool policanbent_dumbms2_error_bat0_under_volt_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t policanbent_dumbms2_error_bat1_under_volt_encode(double value)
{
    return (uint8_t)(value);
}

double policanbent_dumbms2_error_bat1_under_volt_decode(uint8_t value)
{
    return ((double)value);
}

bool policanbent_dumbms2_error_bat1_under_volt_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t policanbent_dumbms2_error_bat2_under_volt_encode(double value)
{
    return (uint8_t)(value);
}

double policanbent_dumbms2_error_bat2_under_volt_decode(uint8_t value)
{
    return ((double)value);
}

bool policanbent_dumbms2_error_bat2_under_volt_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t policanbent_dumbms2_error_bat3_under_volt_encode(double value)
{
    return (uint8_t)(value);
}

double policanbent_dumbms2_error_bat3_under_volt_decode(uint8_t value)
{
    return ((double)value);
}

bool policanbent_dumbms2_error_bat3_under_volt_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t policanbent_dumbms2_error_bat4_under_volt_encode(double value)
{
    return (uint8_t)(value);
}

double policanbent_dumbms2_error_bat4_under_volt_decode(uint8_t value)
{
    return ((double)value);
}

bool policanbent_dumbms2_error_bat4_under_volt_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

int policanbent_dumbms1_data_pack(
    uint8_t *dst_p,
    const struct policanbent_dumbms1_data_t *src_p,
    size_t size)
{
    if (size < 5u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 5);

    dst_p[0] |= pack_left_shift_u8(src_p->bat0_voltage, 0u, 0xffu);
    dst_p[1] |= pack_left_shift_u8(src_p->bat1_voltage, 0u, 0xffu);
    dst_p[2] |= pack_left_shift_u8(src_p->bat2_voltage, 0u, 0xffu);
    dst_p[3] |= pack_left_shift_u8(src_p->bat3_voltage, 0u, 0xffu);
    dst_p[4] |= pack_left_shift_u8(src_p->bat4_voltage, 0u, 0xffu);

    return (5);
}

int policanbent_dumbms1_data_unpack(
    struct policanbent_dumbms1_data_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 5u) {
        return (-EINVAL);
    }

    dst_p->bat0_voltage = unpack_right_shift_u8(src_p[0], 0u, 0xffu);
    dst_p->bat1_voltage = unpack_right_shift_u8(src_p[1], 0u, 0xffu);
    dst_p->bat2_voltage = unpack_right_shift_u8(src_p[2], 0u, 0xffu);
    dst_p->bat3_voltage = unpack_right_shift_u8(src_p[3], 0u, 0xffu);
    dst_p->bat4_voltage = unpack_right_shift_u8(src_p[4], 0u, 0xffu);

    return (0);
}

int policanbent_dumbms1_data_init(struct policanbent_dumbms1_data_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct policanbent_dumbms1_data_t));

    return 0;
}

uint8_t policanbent_dumbms1_data_bat0_voltage_encode(double value)
{
    return (uint8_t)(value / 0.1);
}

double policanbent_dumbms1_data_bat0_voltage_decode(uint8_t value)
{
    return ((double)value * 0.1);
}

bool policanbent_dumbms1_data_bat0_voltage_is_in_range(uint8_t value)
{
    return (value <= 150u);
}

uint8_t policanbent_dumbms1_data_bat1_voltage_encode(double value)
{
    return (uint8_t)(value / 0.1);
}

double policanbent_dumbms1_data_bat1_voltage_decode(uint8_t value)
{
    return ((double)value * 0.1);
}

bool policanbent_dumbms1_data_bat1_voltage_is_in_range(uint8_t value)
{
    return (value <= 150u);
}

uint8_t policanbent_dumbms1_data_bat2_voltage_encode(double value)
{
    return (uint8_t)(value / 0.1);
}

double policanbent_dumbms1_data_bat2_voltage_decode(uint8_t value)
{
    return ((double)value * 0.1);
}

bool policanbent_dumbms1_data_bat2_voltage_is_in_range(uint8_t value)
{
    return (value <= 150u);
}

uint8_t policanbent_dumbms1_data_bat3_voltage_encode(double value)
{
    return (uint8_t)(value / 0.1);
}

double policanbent_dumbms1_data_bat3_voltage_decode(uint8_t value)
{
    return ((double)value * 0.1);
}

bool policanbent_dumbms1_data_bat3_voltage_is_in_range(uint8_t value)
{
    return (value <= 150u);
}

uint8_t policanbent_dumbms1_data_bat4_voltage_encode(double value)
{
    return (uint8_t)(value / 0.1);
}

double policanbent_dumbms1_data_bat4_voltage_decode(uint8_t value)
{
    return ((double)value * 0.1);
}

bool policanbent_dumbms1_data_bat4_voltage_is_in_range(uint8_t value)
{
    return (value <= 150u);
}

int policanbent_dumbms2_data_pack(
    uint8_t *dst_p,
    const struct policanbent_dumbms2_data_t *src_p,
    size_t size)
{
    if (size < 5u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 5);

    dst_p[0] |= pack_left_shift_u8(src_p->bat0_voltage, 0u, 0xffu);
    dst_p[1] |= pack_left_shift_u8(src_p->bat1_voltage, 0u, 0xffu);
    dst_p[2] |= pack_left_shift_u8(src_p->bat2_voltage, 0u, 0xffu);
    dst_p[3] |= pack_left_shift_u8(src_p->bat3_voltage, 0u, 0xffu);
    dst_p[4] |= pack_left_shift_u8(src_p->bat4_voltage, 0u, 0xffu);

    return (5);
}

int policanbent_dumbms2_data_unpack(
    struct policanbent_dumbms2_data_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 5u) {
        return (-EINVAL);
    }

    dst_p->bat0_voltage = unpack_right_shift_u8(src_p[0], 0u, 0xffu);
    dst_p->bat1_voltage = unpack_right_shift_u8(src_p[1], 0u, 0xffu);
    dst_p->bat2_voltage = unpack_right_shift_u8(src_p[2], 0u, 0xffu);
    dst_p->bat3_voltage = unpack_right_shift_u8(src_p[3], 0u, 0xffu);
    dst_p->bat4_voltage = unpack_right_shift_u8(src_p[4], 0u, 0xffu);

    return (0);
}

int policanbent_dumbms2_data_init(struct policanbent_dumbms2_data_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct policanbent_dumbms2_data_t));

    return 0;
}

uint8_t policanbent_dumbms2_data_bat0_voltage_encode(double value)
{
    return (uint8_t)(value / 0.1);
}

double policanbent_dumbms2_data_bat0_voltage_decode(uint8_t value)
{
    return ((double)value * 0.1);
}

bool policanbent_dumbms2_data_bat0_voltage_is_in_range(uint8_t value)
{
    return (value <= 150u);
}

uint8_t policanbent_dumbms2_data_bat1_voltage_encode(double value)
{
    return (uint8_t)(value / 0.1);
}

double policanbent_dumbms2_data_bat1_voltage_decode(uint8_t value)
{
    return ((double)value * 0.1);
}

bool policanbent_dumbms2_data_bat1_voltage_is_in_range(uint8_t value)
{
    return (value <= 150u);
}

uint8_t policanbent_dumbms2_data_bat2_voltage_encode(double value)
{
    return (uint8_t)(value / 0.1);
}

double policanbent_dumbms2_data_bat2_voltage_decode(uint8_t value)
{
    return ((double)value * 0.1);
}

bool policanbent_dumbms2_data_bat2_voltage_is_in_range(uint8_t value)
{
    return (value <= 150u);
}

uint8_t policanbent_dumbms2_data_bat3_voltage_encode(double value)
{
    return (uint8_t)(value / 0.1);
}

double policanbent_dumbms2_data_bat3_voltage_decode(uint8_t value)
{
    return ((double)value * 0.1);
}

bool policanbent_dumbms2_data_bat3_voltage_is_in_range(uint8_t value)
{
    return (value <= 150u);
}

uint8_t policanbent_dumbms2_data_bat4_voltage_encode(double value)
{
    return (uint8_t)(value / 0.1);
}

double policanbent_dumbms2_data_bat4_voltage_decode(uint8_t value)
{
    return ((double)value * 0.1);
}

bool policanbent_dumbms2_data_bat4_voltage_is_in_range(uint8_t value)
{
    return (value <= 150u);
}

int policanbent_whereami_raw_data_pack(
    uint8_t *dst_p,
    const struct policanbent_whereami_raw_data_t *src_p,
    size_t size)
{
    if (size < 4u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 4);

    dst_p[0] |= pack_left_shift_u16(src_p->raw_speed, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(src_p->raw_speed, 8u, 0xffu);
    dst_p[2] |= pack_left_shift_u16(src_p->raw_distance, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(src_p->raw_distance, 8u, 0xffu);

    return (4);
}

int policanbent_whereami_raw_data_unpack(
    struct policanbent_whereami_raw_data_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 4u) {
        return (-EINVAL);
    }

    dst_p->raw_speed = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    dst_p->raw_speed |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->raw_distance = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    dst_p->raw_distance |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);

    return (0);
}

int policanbent_whereami_raw_data_init(struct policanbent_whereami_raw_data_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct policanbent_whereami_raw_data_t));

    return 0;
}

uint16_t policanbent_whereami_raw_data_raw_speed_encode(double value)
{
    return (uint16_t)(value / 0.01);
}

double policanbent_whereami_raw_data_raw_speed_decode(uint16_t value)
{
    return ((double)value * 0.01);
}

bool policanbent_whereami_raw_data_raw_speed_is_in_range(uint16_t value)
{
    return (value <= 20000u);
}

uint16_t policanbent_whereami_raw_data_raw_distance_encode(double value)
{
    return (uint16_t)(value);
}

double policanbent_whereami_raw_data_raw_distance_decode(uint16_t value)
{
    return ((double)value);
}

bool policanbent_whereami_raw_data_raw_distance_is_in_range(uint16_t value)
{
    return (value <= 20000u);
}

int policanbent_whereami_pos_uncert_pack(
    uint8_t *dst_p,
    const struct policanbent_whereami_pos_uncert_t *src_p,
    size_t size)
{
    if (size < 2u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 2);

    dst_p[0] |= pack_left_shift_u16(src_p->pos_uncertainty, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(src_p->pos_uncertainty, 8u, 0xffu);

    return (2);
}

int policanbent_whereami_pos_uncert_unpack(
    struct policanbent_whereami_pos_uncert_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 2u) {
        return (-EINVAL);
    }

    dst_p->pos_uncertainty = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    dst_p->pos_uncertainty |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);

    return (0);
}

int policanbent_whereami_pos_uncert_init(struct policanbent_whereami_pos_uncert_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct policanbent_whereami_pos_uncert_t));

    return 0;
}

uint16_t policanbent_whereami_pos_uncert_pos_uncertainty_encode(double value)
{
    return (uint16_t)(value / 0.01);
}

double policanbent_whereami_pos_uncert_pos_uncertainty_decode(uint16_t value)
{
    return ((double)value * 0.01);
}

bool policanbent_whereami_pos_uncert_pos_uncertainty_is_in_range(uint16_t value)
{
    return (value <= 10000u);
}
