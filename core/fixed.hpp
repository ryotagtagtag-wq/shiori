#ifndef SHIORI_CORE_FIXED_HPP
#define SHIORI_CORE_FIXED_HPP

#include <cstdint>

namespace shiori {

// Q8.8 固定小数点。1.0 = 256。
using fix16 = int16_t;

constexpr fix16 FIX(int v) {
    return static_cast<fix16>(static_cast<int32_t>(v) << 8);
}

constexpr fix16 FIXF(int v, int f) {
    return static_cast<fix16>((static_cast<int32_t>(v) << 8) | (static_cast<uint32_t>(f) & 0xFF));
}

inline int fix_to_int(fix16 v) {
    return static_cast<int>(v) >> 8;
}

inline int fix_to_int_round(fix16 v) {
    return (static_cast<int>(v) + 128) >> 8;
}

inline fix16 fmul(fix16 a, fix16 b) {
    return static_cast<fix16>((static_cast<int32_t>(a) * static_cast<int32_t>(b)) >> 8);
}

inline fix16 fdiv(fix16 a, fix16 b) {
    return static_cast<fix16>((static_cast<int32_t>(a) << 8) / static_cast<int32_t>(b));
}

inline fix16 fadd(fix16 a, fix16 b) {
    return static_cast<fix16>(static_cast<int32_t>(a) + static_cast<int32_t>(b));
}

inline fix16 fsub(fix16 a, fix16 b) {
    return static_cast<fix16>(static_cast<int32_t>(a) - static_cast<int32_t>(b));
}

} // namespace shiori

#endif // SHIORI_CORE_FIXED_HPP
