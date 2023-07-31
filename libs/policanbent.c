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
 * This file was generated by cantools version 38.0.2 Mon Jul 31 12:50:42 2023.
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

uint16_t policanbent_bob_hs_displacement_hs_displacement_encode(double value)
{
    return (uint16_t)((value - 1.0) / 0.1);
}

double policanbent_bob_hs_displacement_hs_displacement_decode(uint16_t value)
{
    return (((double)value * 0.1) + 1.0);
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

int policanbent_miriam_gps_data_pack(
    uint8_t *dst_p,
    const struct policanbent_miriam_gps_data_t *src_p,
    size_t size)
{
    if (size < 4u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 4);

    dst_p[0] |= pack_left_shift_u16(src_p->gps_speed, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(src_p->gps_speed, 8u, 0xffu);
    dst_p[2] |= pack_left_shift_u16(src_p->gps_displacement, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(src_p->gps_displacement, 8u, 0xffu);

    return (4);
}

int policanbent_miriam_gps_data_unpack(
    struct policanbent_miriam_gps_data_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 4u) {
        return (-EINVAL);
    }

    dst_p->gps_speed = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    dst_p->gps_speed |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->gps_displacement = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    dst_p->gps_displacement |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);

    return (0);
}

uint16_t policanbent_miriam_gps_data_gps_speed_encode(double value)
{
    return (uint16_t)(value / 0.01);
}

double policanbent_miriam_gps_data_gps_speed_decode(uint16_t value)
{
    return ((double)value * 0.01);
}

bool policanbent_miriam_gps_data_gps_speed_is_in_range(uint16_t value)
{
    return (value <= 20000u);
}

uint16_t policanbent_miriam_gps_data_gps_displacement_encode(double value)
{
    return (uint16_t)(value);
}

double policanbent_miriam_gps_data_gps_displacement_decode(uint16_t value)
{
    return ((double)value);
}

bool policanbent_miriam_gps_data_gps_displacement_is_in_range(uint16_t value)
{
    return (value <= 20000u);
}

int policanbent_miriam_gps_coords_pack(
    uint8_t *dst_p,
    const struct policanbent_miriam_gps_coords_t *src_p,
    size_t size)
{
    uint32_t gps_latitude;
    uint32_t gps_longitude;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    gps_latitude = (uint32_t)src_p->gps_latitude;
    dst_p[0] |= pack_left_shift_u32(gps_latitude, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u32(gps_latitude, 8u, 0xffu);
    dst_p[2] |= pack_right_shift_u32(gps_latitude, 16u, 0xffu);
    dst_p[3] |= pack_right_shift_u32(gps_latitude, 24u, 0xffu);
    gps_longitude = (uint32_t)src_p->gps_longitude;
    dst_p[4] |= pack_left_shift_u32(gps_longitude, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u32(gps_longitude, 8u, 0xffu);
    dst_p[6] |= pack_right_shift_u32(gps_longitude, 16u, 0xffu);
    dst_p[7] |= pack_right_shift_u32(gps_longitude, 24u, 0xffu);

    return (8);
}

int policanbent_miriam_gps_coords_unpack(
    struct policanbent_miriam_gps_coords_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint32_t gps_latitude;
    uint32_t gps_longitude;

    if (size < 8u) {
        return (-EINVAL);
    }

    gps_latitude = unpack_right_shift_u32(src_p[0], 0u, 0xffu);
    gps_latitude |= unpack_left_shift_u32(src_p[1], 8u, 0xffu);
    gps_latitude |= unpack_left_shift_u32(src_p[2], 16u, 0xffu);
    gps_latitude |= unpack_left_shift_u32(src_p[3], 24u, 0xffu);
    dst_p->gps_latitude = (int32_t)gps_latitude;
    gps_longitude = unpack_right_shift_u32(src_p[4], 0u, 0xffu);
    gps_longitude |= unpack_left_shift_u32(src_p[5], 8u, 0xffu);
    gps_longitude |= unpack_left_shift_u32(src_p[6], 16u, 0xffu);
    gps_longitude |= unpack_left_shift_u32(src_p[7], 24u, 0xffu);
    dst_p->gps_longitude = (int32_t)gps_longitude;

    return (0);
}

int32_t policanbent_miriam_gps_coords_gps_latitude_encode(double value)
{
    return (int32_t)(value / 0.000001);
}

double policanbent_miriam_gps_coords_gps_latitude_decode(int32_t value)
{
    return ((double)value * 0.000001);
}

bool policanbent_miriam_gps_coords_gps_latitude_is_in_range(int32_t value)
{
    return ((value >= -90000000) && (value <= 90000000));
}

int32_t policanbent_miriam_gps_coords_gps_longitude_encode(double value)
{
    return (int32_t)(value / 0.000001);
}

double policanbent_miriam_gps_coords_gps_longitude_decode(int32_t value)
{
    return ((double)value * 0.000001);
}

bool policanbent_miriam_gps_coords_gps_longitude_is_in_range(int32_t value)
{
    return ((value >= -180000000) && (value <= 180000000));
}

int policanbent_miriam_air_quality_pack(
    uint8_t *dst_p,
    const struct policanbent_miriam_air_quality_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_left_shift_u32(src_p->co2_level, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u32(src_p->co2_level, 8u, 0xffu);
    dst_p[2] |= pack_right_shift_u32(src_p->co2_level, 16u, 0xffu);
    dst_p[3] |= pack_right_shift_u32(src_p->co2_level, 24u, 0xffu);
    dst_p[4] |= pack_left_shift_u32(src_p->tvoc, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u32(src_p->tvoc, 8u, 0xffu);
    dst_p[6] |= pack_right_shift_u32(src_p->tvoc, 16u, 0xffu);
    dst_p[7] |= pack_right_shift_u32(src_p->tvoc, 24u, 0xffu);

    return (8);
}

int policanbent_miriam_air_quality_unpack(
    struct policanbent_miriam_air_quality_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->co2_level = unpack_right_shift_u32(src_p[0], 0u, 0xffu);
    dst_p->co2_level |= unpack_left_shift_u32(src_p[1], 8u, 0xffu);
    dst_p->co2_level |= unpack_left_shift_u32(src_p[2], 16u, 0xffu);
    dst_p->co2_level |= unpack_left_shift_u32(src_p[3], 24u, 0xffu);
    dst_p->tvoc = unpack_right_shift_u32(src_p[4], 0u, 0xffu);
    dst_p->tvoc |= unpack_left_shift_u32(src_p[5], 8u, 0xffu);
    dst_p->tvoc |= unpack_left_shift_u32(src_p[6], 16u, 0xffu);
    dst_p->tvoc |= unpack_left_shift_u32(src_p[7], 24u, 0xffu);

    return (0);
}

uint32_t policanbent_miriam_air_quality_co2_level_encode(double value)
{
    return (uint32_t)(value / 0.00001);
}

double policanbent_miriam_air_quality_co2_level_decode(uint32_t value)
{
    return ((double)value * 0.00001);
}

bool policanbent_miriam_air_quality_co2_level_is_in_range(uint32_t value)
{
    return ((value >= 20000000u) && (value <= 300000000u));
}

uint32_t policanbent_miriam_air_quality_tvoc_encode(double value)
{
    return (uint32_t)(value / 0.00001);
}

double policanbent_miriam_air_quality_tvoc_decode(uint32_t value)
{
    return ((double)value * 0.00001);
}

bool policanbent_miriam_air_quality_tvoc_is_in_range(uint32_t value)
{
    return (value <= 400000000u);
}

int policanbent_miriam_temp_pack(
    uint8_t *dst_p,
    const struct policanbent_miriam_temp_t *src_p,
    size_t size)
{
    if (size < 2u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 2);

    dst_p[0] |= pack_left_shift_u16(src_p->temperature, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(src_p->temperature, 8u, 0xffu);

    return (2);
}

int policanbent_miriam_temp_unpack(
    struct policanbent_miriam_temp_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 2u) {
        return (-EINVAL);
    }

    dst_p->temperature = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    dst_p->temperature |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);

    return (0);
}

uint16_t policanbent_miriam_temp_temperature_encode(double value)
{
    return (uint16_t)(value / 0.01);
}

double policanbent_miriam_temp_temperature_decode(uint16_t value)
{
    return ((double)value * 0.01);
}

bool policanbent_miriam_temp_temperature_is_in_range(uint16_t value)
{
    return (value <= 6000u);
}

int policanbent_miriam_gps_other_pack(
    uint8_t *dst_p,
    const struct policanbent_miriam_gps_other_t *src_p,
    size_t size)
{
    if (size < 2u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 2);

    dst_p[0] |= pack_left_shift_u16(src_p->altitude, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(src_p->altitude, 8u, 0xffu);

    return (2);
}

int policanbent_miriam_gps_other_unpack(
    struct policanbent_miriam_gps_other_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 2u) {
        return (-EINVAL);
    }

    dst_p->altitude = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    dst_p->altitude |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);

    return (0);
}

uint16_t policanbent_miriam_gps_other_altitude_encode(double value)
{
    return (uint16_t)(value - 1.0);
}

double policanbent_miriam_gps_other_altitude_decode(uint16_t value)
{
    return ((double)value + 1.0);
}

bool policanbent_miriam_gps_other_altitude_is_in_range(uint16_t value)
{
    return (value <= 2999u);
}
