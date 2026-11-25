#ifndef SHIORI_CORE_STORY_STORYMANAGER_HPP
#define SHIORI_CORE_STORY_STORYMANAGER_HPP

#include <cstdint>

#include "core/config.hpp"
#include "core/story/Story.hpp"
#include "core/story/StoryChoice.hpp"
#include "core/story/StoryNode.hpp"

namespace shiori::story {

// ストーリー管理。現在のノード、フラグ、選択履歴を保持する。
// 動的確保を行わないため、すべて固定長配列・プールで管理する。
struct StoryManager {
    NodeId currentNode = 0;
    std::uint32_t flags[8] = {}; // 256フラグ用ビットマップ
    std::uint16_t choiceHistory[config::max_choice_history] = {};
    std::uint8_t choiceCount = 0;

    // 指定ノードに遷移する。
    void gotoNode(NodeId nodeId) {
        currentNode = nodeId;
    }

    // 現在のノードIDを取得する。
    NodeId getCurrentNode() const {
        return currentNode;
    }

    // フラグが設定済みか。
    bool isFlagSet(std::uint16_t flagId) const {
        return story::isFlagSet(flags, flagId);
    }

    // フラグを設定する。
    void setFlag(std::uint16_t flagId) {
        story::setFlag(flags, flagId);
    }

    // フラグを解除する。
    void clearFlag(std::uint16_t flagId) {
        story::clearFlag(flags, flagId);
    }

    // 選択履歴を記録する。
    // プールが一杯の場合は古い履歴から上書きする。
    void recordChoice(std::uint16_t choiceId) {
        if (choiceCount < config::max_choice_history) {
            choiceHistory[choiceCount] = choiceId;
            ++choiceCount;
        } else {
            // プール満杯：先頭からシフトして末尾に追加
            for (std::uint8_t i = 0; i < config::max_choice_history - 1; ++i) {
                choiceHistory[i] = choiceHistory[i + 1];
            }
            choiceHistory[config::max_choice_history - 1] = choiceId;
        }
    }

    // 指定選択肢が表示条件を満たすか。
    bool isChoiceVisible(const StoryChoice& choice) const {
        switch (choice.condition) {
            case ChoiceCondition::None:
                return true;
            case ChoiceCondition::FlagSet:
                return isFlagSet(choice.conditionFlag);
            case ChoiceCondition::FlagUnset:
                return !isFlagSet(choice.conditionFlag);
            default:
                return false;
        }
    }
};

} // namespace shiori::story

#endif // SHIORI_CORE_STORY_STORYMANAGER_HPP
