#ifndef SHIORI_CORE_STORY_STORY_HPP
#define SHIORI_CORE_STORY_STORY_HPP

#include <cstdint>

#include "core/save/Bookmark.hpp"

namespace shiori::story {

// 物語フラグと分岐の判定。
// TODO(ryo): フラグ管理、分岐ID解決、台本参照を実装する。

inline bool isFlagSet(std::uint16_t flagId) {
    // 仮のプレースホルダ。
    return false;
}

} // namespace shiori::story

#endif // SHIORI_CORE_STORY_STORY_HPP
