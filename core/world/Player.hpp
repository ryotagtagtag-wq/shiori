#ifndef SHIORI_CORE_WORLD_PLAYER_HPP
#define SHIORI_CORE_WORLD_PLAYER_HPP

#include <cstdint>

#include "core/fixed.hpp"
#include "core/config.hpp"

namespace shiori::world {

// プレイヤー向き。
enum class Direction : std::uint8_t {
    Up,
    Down,
    Left,
    Right,
};

// プレイヤー状態。
// ゲーム中に動的確保を行わないため、すべて固定長メンバーとする。
struct Player {
    std::uint16_t mapId = 0;      // 現在のマップID
    std::int16_t tileX = 0;       // タイル単位のX座標
    std::int16_t tileY = 0;       // タイル単位のY座標
    Direction facing = Direction::Down;
    fix16 hp = shiori::FIX(100);
    fix16 mp = shiori::FIX(50);
    fix16 atk = shiori::FIX(10);
    fix16 def = shiori::FIX(5);
};

// プレイヤーを指定タイルへ移動させる。
// 衝突判定・マップ遷移は World 側で行うため、ここでは座標のみ更新する。
inline void moveTo(Player& player, std::int16_t tx, std::int16_t ty) {
    player.tileX = tx;
    player.tileY = ty;
}

// プレイヤーの向きを変更する。
inline void face(Player& player, Direction dir) {
    player.facing = dir;
}

} // namespace shiori::world

#endif // SHIORI_CORE_WORLD_PLAYER_HPP
