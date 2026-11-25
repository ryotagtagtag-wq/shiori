#ifndef SHIORI_CORE_SAVE_BOOKMARK_HPP
#define SHIORI_CORE_SAVE_BOOKMARK_HPP

#include <cstddef>
#include <cstdint>

namespace shiori::save {

// 栞（セーブデータ）の1スロット分。
// 詳細フィールドは物語エージェントと Ryo の仕様確定後に確定する。
// TODO(ryo): 場所ID、フラグビットマップ、選択履歴、プレイ時間等を追加する。
struct Bookmark {
    std::uint8_t slot = 0;
    std::uint16_t mapId = 0;
    std::uint16_t flags = 0;
    std::uint8_t choiceCount = 0;
    // 固定長バッファに格納するため、可変長メンバーは持たない。
};

static_assert(sizeof(Bookmark) <= 64, "Bookmark は 64 バイト以内に抑える");

} // namespace shiori::save

#endif // SHIORI_CORE_SAVE_BOOKMARK_HPP
