#ifndef SHIORI_CORE_STORY_STORYCHOICE_HPP
#define SHIORI_CORE_STORY_STORYCHOICE_HPP

#include <cstdint>

#include "core/story/StoryNode.hpp"

namespace shiori::story {

// 選択肢の発動条件。
enum class ChoiceCondition : std::uint8_t {
    None,           // 常に表示
    FlagSet,        // 指定フラグが設定済みのときのみ表示
    FlagUnset,      // 指定フラグが未設定のときのみ表示
};

// 物語選択肢の定義。
// 固定長メンバーのみを持つ（動的確保禁止）。
struct StoryChoice {
    std::uint8_t choiceId = 0;    // 選択肢ID（A/B/C など）
    NodeId nextNode = 0;          // 選択時の遷移先ノードID
    ChoiceCondition condition = ChoiceCondition::None;
    std::uint16_t conditionFlag = 0; // 条件に使用するフラグID
    std::uint16_t setFlag = 0;      // 選択時に設定するフラグID（0 = なし）
};

} // namespace shiori::story

#endif // SHIORI_CORE_STORY_STORYCHOICE_HPP
