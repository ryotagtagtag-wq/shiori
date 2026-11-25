#ifndef SHIORI_PLATFORM_PC_PCAUDIO_HPP
#define SHIORI_PLATFORM_PC_PCAUDIO_HPP

#include "hal/IAudio.hpp"

namespace shiori::platform::pc {

// PC 向け音声実装。未実装のため no-op。
class PcAudio : public hal::IAudio {
public:
    void playSfx(std::uint16_t id) override;
    void playBgm(std::uint16_t id) override;
    void stopBgm() override;
};

} // namespace shiori::platform::pc

#endif // SHIORI_PLATFORM_PC_PCAUDIO_HPP
