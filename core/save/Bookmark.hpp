#ifndef SHIORI_CORE_SAVE_BOOKMARK_HPP
#define SHIORI_CORE_SAVE_BOOKMARK_HPP

#include <cstddef>
#include <cstdint>

#include "core/fixed.hpp"
#include "core/config.hpp"

namespace shiori::save {

// 栞（セーブデータ）の1スロット分。
// 拡張構成：場所ID、256フラグビットマップ、選択履歴数、プレイ時間、所持品、ステータス。
// 固定長バッファに格納するため、可変長メンバーは持たない。
struct Bookmark {
    std::uint8_t slot = 0;
    std::uint16_t mapId = 0;
    std::uint32_t flagBits[8] = {}; // 256フラグ用ビットマップ (8 * 32bit = 256bit)
    std::uint8_t choiceCount = 0;
    std::uint32_t playTimeMs = 0;
    std::uint16_t items[config::max_inventory_items] = {}; // 所持品アイテムID
    std::uint8_t itemCount = 0;
    fix16 hp = 0;
    fix16 mp = 0;
    fix16 atk = 0;
    fix16 def = 0;
};

static_assert(sizeof(Bookmark) <= 128, "Bookmark は 128 バイト以内に抑える");

} // namespace shiori::save

#endif // SHIORI_CORE_SAVE_BOOKMARK_HPP
