#include "platform/pc/PcAudio.hpp"

#include "assets/sfx/swing_adpcm.hpp"
#include "assets/sfx/magic1_adpcm.hpp"
#include "assets/sfx/coin_adpcm.hpp"
#include "assets/sfx/door_adpcm.hpp"
#include "assets/sfx/interface1_adpcm.hpp"

#include <cstdint>
#include <cstdio>

namespace shiori::platform::pc {

void PcAudio::decodeAndPlay(const std::uint8_t* data, std::uint32_t size) {
    m_decoder.reset();
    std::uint32_t offset = 0;
    while (offset < size) {
        std::uint8_t count = m_decoder.decodeByte(data[offset]);
        ++offset;
        // デコード済みサンプルを蓄積（ここでは再生シミュレーションとしてカウントのみ）
        (void)m_decoder.sampleCount();
        (void)count;
    }
    m_decoder.clear();
}

void PcAudio::playSfx(std::uint16_t id) {
    const std::uint8_t* data = nullptr;
    std::uint32_t size = 0;

    switch (static_cast<SfxId>(id)) {
        case SfxId::Swing:
            data = swing_adpcm;
            size = swing_adpcm_size;
            break;
        case SfxId::Magic1:
            data = magic1_adpcm;
            size = magic1_adpcm_size;
            break;
        case SfxId::Coin:
            data = coin_adpcm;
            size = coin_adpcm_size;
            break;
        case SfxId::Door:
            data = door_adpcm;
            size = door_adpcm_size;
            break;
        case SfxId::Interface1:
            data = interface1_adpcm;
            size = interface1_adpcm_size;
            break;
        default:
            return;
    }

    decodeAndPlay(data, size);
    std::printf("[pc audio] playSfx id=%u size=%u\n", id, size);
}

void PcAudio::playBgm(std::uint16_t id) {
    (void)id;
    // TODO(ryo): BGM の ADPCM 変換と再生を実装する（MP3/OGG は未対応）。
}

void PcAudio::stopBgm() {
    // TODO(ryo): BGM 停止を実装する。
}

} // namespace shiori::platform::pc
