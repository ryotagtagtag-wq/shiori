#ifndef SHIORI_CORE_WORLD_MAP_HPP
#define SHIORI_CORE_WORLD_MAP_HPP

#include <cstdint>

#include "core/config.hpp"

namespace shiori::world {

// マップの定義。詳細は未確定。
// TODO(ryo): タイル配列、マップサイズ、遷移先情報を追加する。
struct Map {
    std::uint16_t id = 0;
    std::uint16_t width = 0;
    std::uint16_t height = 0;
};

} // namespace shiori::world

#endif // SHIORI_CORE_WORLD_MAP_HPP
