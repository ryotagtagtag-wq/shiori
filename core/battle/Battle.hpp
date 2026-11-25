#ifndef SHIORI_CORE_BATTLE_BATTLE_HPP
#define SHIORI_CORE_BATTLE_BATTLE_HPP

#include <cstdint>

namespace shiori::battle {

// 戦闘計算。ダメージ式は整数演算のみで固定する。
// ダメージ式: attack - defense (仕様確定済み)

inline std::int32_t calcDamage(std::int32_t attack, std::int32_t defense) {
    return attack - defense;
}

} // namespace shiori::battle

#endif // SHIORI_CORE_BATTLE_BATTLE_HPP
