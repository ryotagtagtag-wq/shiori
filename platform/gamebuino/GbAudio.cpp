#include "platform/gamebuino/GbAudio.hpp"

// TODO(ryo): Gamebuino-META 音声実装。
//   - playSfx(): ImaAdpcmDecoder でフラッシュ常駐ADPCM配列をデコード・再生
//   - playBgm(): SDカード (gb.storage / SdFat) からWAV/ADPCMをストリーミング再生
//   - stopBgm(): BGM 停止
// 実機では Gamebuino-META ライブラリ (gamebuino/Gamebuino META) を lib_deps に追加し、
// gb.sound / gb.storage API を使用して実装すること。

GbAudio::GbAudio() : m_decoder() {}

GbAudio::~GbAudio() {
    stopBgm();
}

void GbAudio::playSfx(std::uint16_t id) {
    (void)id;
    m_decoder.reset();
    m_decoder.clear();
    // TODO(ryo): フラッシュ常駐ADPCM配列 (swing_adpcm 等) をデコード・再生する。
    // 例: switch (id) { case SfxId::Swing: decodeAndPlay(swing_adpcm, swing_adpcm_size); ... }
}

void GbAudio::playBgm(std::uint16_t id) {
    (void)id;
    stopBgm();
    m_bgm_id = id;
    m_bgm_playing = true;
    // TODO(ryo): SDカード (gb.storage / SdFat) からWAV/ADPCMファイルを開き、
    // 順次読み込み・デコード・再生するストリーミング処理を実装する。
}

void GbAudio::stopBgm() {
    m_bgm_playing = false;
    m_bgm_id = 0;
    // TODO(ryo): SDカードファイルハンドルを閉じ、再生を停止する。
}

void GbAudio::update() {
    if (!m_bgm_playing) {
        return;
    }
    // TODO(ryo): SDカードから次のチャンクを読み込み、ImaAdpcmDecoder でデコード・再生する。
    // 毎フレーム呼び出すことでストリーミング再生を実現する。
}
