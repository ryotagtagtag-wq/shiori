#ifndef SHIORI_CORE_AI_AI_HPP
#define SHIORI_CORE_AI_AI_HPP

#include <cstdint>

#include "core/config.hpp"

namespace shiori::ai {

// ゲーム内 AI。実機では重み付き決定木または重み付きランダム選択を使用し、
// 動的確保・大規模推論は行わない。
// TODO(ryo): 決定木・重み付き選択、選択履歴バッファを実装する。

struct ChoiceHistory {
    std::uint16_t choiceId[config::max_ai_history] = {};
    std::uint8_t count = 0;
};

} // namespace shiori::ai

#endif // SHIORI_CORE_AI_AI_HPP
