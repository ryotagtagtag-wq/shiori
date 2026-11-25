#include "platform/gamebuino/GbDisplay.hpp"

// TODO(ryo): Gamebuino-META (Arduino / SAMD21) へ実装する。
// <Arduino.h> および Gamebuino-META ライブラリが必要。

void GbDisplay::clear() {
    // 未実装
    (void)0;
}

void GbDisplay::drawTile(std::int16_t x, std::int16_t y, std::uint16_t tileId) {
    (void)x;
    (void)y;
    (void)tileId;
}

void GbDisplay::drawSprite(std::int16_t x, std::int16_t y, std::uint16_t spriteId) {
    (void)x;
    (void)y;
    (void)spriteId;
}

void GbDisplay::present() {
    // 未実装
}
