#ifndef SHIORI_CORE_WORLD_WORLD_HPP
#define SHIORI_CORE_WORLD_WORLD_HPP

#include <cstdint>

#include "core/config.hpp"
#include "core/world/Map.hpp"
#include "core/world/Player.hpp"

namespace shiori::world {

// ワールド状態。プレイヤーと現在のマップを保持する。
// 動的確保を行わないため、マップ定義は固定長プールで管理する。
struct World {
    Player player;
    Map currentMap;
    std::uint16_t currentMapId = 0;

    // プレイヤーを指定タイルへ移動させる。
    void movePlayer(std::int16_t tx, std::int16_t ty) {
        moveTo(player, tx, ty);
    }

    // プレイヤーの向きを変更する。
    void facePlayer(Direction dir) {
        face(player, dir);
    }

    // マップを切り替える。
    // 遷移先マップの実体読み込みはアセット変換後の const 配列から行うため、
    // ここでは ID の切り替えのみ行う。
    // TODO(ryo): マップ実体読み込み・衝突マップのバインドを追加する。
    void changeMap(std::uint16_t mapId) {
        currentMapId = mapId;
        currentMap.id = mapId;
        // プレイヤーのマップIDも更新
        player.mapId = mapId;
    }
};

} // namespace shiori::world

#endif // SHIORI_CORE_WORLD_WORLD_HPP
