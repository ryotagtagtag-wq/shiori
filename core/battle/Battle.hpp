#ifndef SHIORI_CORE_BATTLE_BATTLE_HPP
#define SHIORI_CORE_BATTLE_BATTLE_HPP

#include <cstdint>

namespace shiori::battle {

// 戦闘計算。ダメージ式は整数演算のみで固定する。
// TODO(ryo): ダメージ式、命中率、ターン制御を実装する。

inline std::int32_t calcDamage(std::int32_t attack, std::int32_t defense) {
    // 仮のプレースホルダ。Ryo の仕様確定後に固定式に差し替える。
    return attack - defense;
}

} // namespace shiori::battle

#endif // SHIORI_CORE_BATTLE_BATTLE_HPP
