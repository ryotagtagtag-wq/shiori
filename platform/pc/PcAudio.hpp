#ifndef SHIORI_PLATFORM_PC_PCAUDIO_HPP
#define SHIORI_PLATFORM_PC_PCAUDIO_HPP

#include <cstdint>

#include "core/audio/ImaAdpcmDecoder.hpp"
#include "hal/IAudio.hpp"

namespace shiori::platform::pc {

// 効果音 ID。
enum class SfxId : std::uint8_t {
    Swing = 0,
    Magic1,
    Coin,
    Door,
    Interface1,
    Count,
};

// PC 向け音声実装。IMA ADPCM デコーダを使用して効果音を再生する（スタブ）。
class PcAudio : public hal::IAudio {
public:
    void playSfx(std::uint16_t id) override;
    void playBgm(std::uint16_t id) override;
    void stopBgm() override;

private:
    void decodeAndPlay(const std::uint8_t* data, std::uint32_t size);

    audio::ImaAdpcmDecoder m_decoder;
};

} // namespace shiori::platform::pc

#endif // SHIORI_PLATFORM_PC_PCAUDIO_HPP
