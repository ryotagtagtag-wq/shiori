#ifndef SHIORI_PLATFORM_PC_PCDISPLAY_HPP
#define SHIORI_PLATFORM_PC_PCDISPLAY_HPP

#include "hal/IDisplay.hpp"

namespace shiori::platform::pc {

// PC 向けディスプレイ実装。
// SDL2 / raylib バックエンドの統合は未完了。現状はスタブ。
class PcDisplay : public hal::IDisplay {
public:
    void clear() override;
    void drawTile(std::int16_t x, std::int16_t y, std::uint16_t tileId) override;
    void drawSprite(std::int16_t x, std::int16_t y, std::uint16_t spriteId) override;
    void present() override;
};

} // namespace shiori::platform::pc

#endif // SHIORI_PLATFORM_PC_PCDISPLAY_HPP
