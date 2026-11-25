#ifndef SHIORI_CORE_STORY_STORYNODE_HPP
#define SHIORI_CORE_STORY_STORYNODE_HPP

#include <cstdint>

namespace shiori::story {

// 物語ノードID。台本ファイルの NODE_XXX に対応する。
using NodeId = std::uint16_t;

// 台本ノードの定義。
// 固定長メンバーのみを持つ（動的確保禁止）。
struct StoryNode {
    NodeId id = 0;
    std::uint16_t mapId = 0;      // ノードが発生するマップID
    std::uint16_t bookmarkId = 0; // ノード到達時に挟む栞ID（0 = なし）
    bool isEnd = false;           // エンディングフラグ
};

} // namespace shiori::story

#endif // SHIORI_CORE_STORY_STORYNODE_HPP
