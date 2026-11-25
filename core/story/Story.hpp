#ifndef SHIORI_CORE_STORY_STORY_HPP
#define SHIORI_CORE_STORY_STORY_HPP

#include <cstdint>

#include "core/config.hpp"
#include "core/save/Bookmark.hpp"

namespace shiori::story {

// 物語フラグと分岐の判定。
// 256フラグを std::uint32_t[8] のビットマップで管理する（固定長、動的確保なし）。

inline bool isFlagSet(std::uint32_t flags[8], std::uint16_t flagId) {
    if (flagId >= config::max_story_flags) {
        return false;
    }
    return (flags[flagId >> 5] >> (flagId & 31)) & 1u;
}

inline void setFlag(std::uint32_t flags[8], std::uint16_t flagId) {
    if (flagId >= config::max_story_flags) {
        return;
    }
    flags[flagId >> 5] |= (1u << (flagId & 31));
}

inline void clearFlag(std::uint32_t flags[8], std::uint16_t flagId) {
    if (flagId >= config::max_story_flags) {
        return;
    }
    flags[flagId >> 5] &= ~(1u << (flagId & 31));
}

} // namespace shiori::story

#endif // SHIORI_CORE_STORY_STORY_HPP
