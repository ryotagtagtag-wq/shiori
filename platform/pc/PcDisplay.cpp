#include "platform/pc/PcDisplay.hpp"

#include <cstdio>

namespace shiori::platform::pc {

void PcDisplay::clear() {
    // TODO(ryo): SDL2 / raylib で画面クリアを実装する。
    std::printf("[display] clear\n");
}

void PcDisplay::drawTile(std::int16_t x, std::int16_t y, std::uint16_t tileId) {
    // TODO(ryo): SDL2 / raylib でタイル描画を実装する。
    (void)x;
    (void)y;
    (void)tileId;
}

void PcDisplay::drawSprite(std::int16_t x, std::int16_t y, std::uint16_t spriteId) {
    // TODO(ryo): SDL2 / raylib でスプライト描画を実装する。
    (void)x;
    (void)y;
    (void)spriteId;
}

void PcDisplay::present() {
    // TODO(ryo): SDL2 / raylib でフレーム確定を実装する。
    std::printf("[display] present\n");
}

} // namespace shiori::platform::pc
