#include "platform/pc/PcAudio.hpp"

#include <cstdint>

namespace shiori::platform::pc {

void PcAudio::playSfx(std::uint16_t id) {
    (void)id;
    // TODO(ryo): PC 音声バックエンドを実装する。
}

void PcAudio::playBgm(std::uint16_t id) {
    (void)id;
    // TODO(ryo): PC 音声バックエンドを実装する。
}

void PcAudio::stopBgm() {
    // TODO(ryo): PC 音声バックエンドを実装する。
}

} // namespace shiori::platform::pc
