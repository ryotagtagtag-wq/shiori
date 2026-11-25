#ifndef SHIORI_PLATFORM_GAMEBUINO_GBDISPLAY_HPP
#define SHIORI_PLATFORM_GAMEBUINO_GBDISPLAY_HPP

#include "hal/IDisplay.hpp"

// Gamebuino META (ST7735 160x128) 向けディスプレイ実装。
// Arduino / Gamebuino-META ライブラリとの連携は未完了。
// TODO(ryo): Gamebuino-META の gb.display を使って実装する。
class GbDisplay : public shiori::hal::IDisplay {
public:
    void clear() override;
    void drawTile(std::int16_t x, std::int16_t y, std::uint16_t tileId) override;
    void drawSprite(std::int16_t x, std::int16_t y, std::uint16_t spriteId) override;
    void present() override;
};

#endif // SHIORI_PLATFORM_GAMEBUINO_GBDISPLAY_HPP
