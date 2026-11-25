#include "platform/gamebuino/GbAudio.hpp"

// TODO(ryo): Gamebuino-META 音声実装。ImaAdpcmDecoder を使用して ADPCM データをデコード・再生する。
void GbAudio::playSfx(std::uint16_t id) {
    (void)id;
    m_decoder.reset();
    m_decoder.clear();
}

void GbAudio::playBgm(std::uint16_t id) {
    (void)id;
    // TODO(ryo): BGM の ADPCM 変換と再生を実装する（MP3/OGG は未対応）。
}

void GbAudio::stopBgm() {
    // TODO(ryo): BGM 停止を実装する。
}
