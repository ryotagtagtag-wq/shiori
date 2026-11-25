#ifndef SHIORI_CORE_BATTLE_BATTLECONTEXT_HPP
#define SHIORI_CORE_BATTLE_BATTLECONTEXT_HPP

#include <cstdint>

#include "core/battle/Battle.hpp"
#include "core/fixed.hpp"

namespace shiori::battle {

// 戦闘参加者のステータス。
struct CombatantStats {
    fix16 hp = shiori::FIX(100);
    fix16 maxHp = shiori::FIX(100);
    fix16 atk = shiori::FIX(10);
    fix16 def = shiori::FIX(5);
};

// 戦闘結果。
struct BattleResult {
    std::int32_t damage = 0;   // 与ダメージ（整数）
    bool targetDefeated = false; // 対象が戦闘不能か
};

// 攻撃ダメージを計算する。
// ダメージ式: attack - defense（仕様確定済み）。最小ダメージは 0。
inline BattleResult calculateAttack(const CombatantStats& attacker,
                                     const CombatantStats& target) {
    BattleResult result;
    const std::int32_t atk = shiori::fix_to_int(attacker.atk);
    const std::int32_t def = shiori::fix_to_int(target.def);
    result.damage = calcDamage(atk, def);
    if (result.damage < 0) {
        result.damage = 0;
    }

    const std::int32_t targetHp = shiori::fix_to_int(target.hp);
    result.targetDefeated = (targetHp - result.damage) <= 0;

    return result;
}

} // namespace shiori::battle

#endif // SHIORI_CORE_BATTLE_BATTLECONTEXT_HPP
