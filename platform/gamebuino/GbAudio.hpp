#ifndef SHIORI_PLATFORM_GAMEBUINO_GBAUDIO_HPP
#define SHIORI_PLATFORM_GAMEBUINO_GBAUDIO_HPP

#include "hal/IAudio.hpp"

// Gamebuino META 向け音声実装。未完了。
// TODO(ryo): Gamebuino-META の音声出力に差し替える。
class GbAudio : public shiori::hal::IAudio {
public:
    void playSfx(std::uint16_t id) override;
    void playBgm(std::uint16_t id) override;
    void stopBgm() override;
};

#endif // SHIORI_PLATFORM_GAMEBUINO_GBAUDIO_HPP
