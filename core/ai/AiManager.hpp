#ifndef SHIORI_CORE_AI_AIMANAGER_HPP
#define SHIORI_CORE_AI_AIMANAGER_HPP

#include <cstdint>

#include "core/config.hpp"
#include "core/story/StoryManager.hpp"

namespace shiori::ai {

// ゲーム内 AI。重み付きランダム選択を使用し、
// 大規模モデルや動的確保を必要とする推論は行わない。
// 旅の案内人は、プレイヤーの選択履歴を記録して会話の分岐に反映する。
struct AiManager {
    story::StoryManager& story;

    explicit AiManager(story::StoryManager& storyMgr) : story(storyMgr) {}

    // プレイヤーの選択履歴に基づいて、重み付きで次の選択肢を提案する。
    // 単純実装：過去に選択された回数が多い選択肢ほど重みを下げる（多様性を確保）。
    // 詳細は TODO(ryo): 重みテーブルと擬似乱数生成をITimerと連携させる。
    std::uint8_t suggestNextChoice(std::uint8_t numChoices) const {
        if (numChoices == 0) {
            return 0;
        }

        // 各選択肢の過去選択回数をカウント
        std::uint8_t counts[16] = {}; // 最大16選択肢まで対応
        const std::uint8_t maxChoices = (numChoices < 16) ? numChoices : 16;
        for (std::uint8_t i = 0; i < story.choiceCount; ++i) {
            const std::uint16_t choiceId = story.choiceHistory[i];
            if (choiceId < maxChoices) {
                ++counts[choiceId];
            }
        }

        // 選択回数が最も少ない選択肢を提案（未選択があればそれを優先）
        std::uint8_t bestChoice = 0;
        std::uint8_t bestCount = counts[0];
        for (std::uint8_t i = 1; i < maxChoices; ++i) {
            if (counts[i] < bestCount) {
                bestCount = counts[i];
                bestChoice = i;
            }
        }

        return bestChoice;
    }
};

} // namespace shiori::ai

#endif // SHIORI_CORE_AI_AIMANAGER_HPP
