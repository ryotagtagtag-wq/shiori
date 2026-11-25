#ifndef SHIORI_CORE_WORLD_MAP_HPP
#define SHIORI_CORE_WORLD_MAP_HPP

#include <cstdint>

#include "core/config.hpp"

namespace shiori::world {

// マップの定義。デフォルトサイズは 32x32 タイル（仕様確定済み）。
// タイル実体データはアセット変換によりフラッシュ常駐の const 配列として生成され、
// 本構造体はメタデータ（ID・サイズ・遷移先情報）のみを保持する。
// TODO(ryo): タイル配列への参照ポインタと遷移先情報を追加する。
struct Map {
    std::uint16_t id = 0;
    std::uint16_t width = 32;
    std::uint16_t height = 32;
};

} // namespace shiori::world

#endif // SHIORI_CORE_WORLD_MAP_HPP
