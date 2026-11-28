#ifndef SHIORI_PLATFORM_GAMEBUINO_GBAUDIO_HPP
#define SHIORI_PLATFORM_GAMEBUINO_GBAUDIO_HPP

#include <cstdint>

#include "core/audio/ImaAdpcmDecoder.hpp"
#include "hal/IAudio.hpp"

// Gamebuino META 向け音声実装。ハイブリッド方式：
//   - playSfx(): フラッシュ常駐ADPCM配列から即座に再生（短い効果音向け）
//   - playBgm(): SDカードからストリーミング再生（長いBGM向け）
// Gamebuino-META ライブラリ未導入のためスタブ実装。実機では
// gb.storage / gb.sound / SdFat 等を使用して実装すること。
// TODO(ryo): Gamebuino-META の音声出力・SDカードAPIに差し替える。
class GbAudio : public shiori::hal::IAudio {
public:
    GbAudio();
    ~GbAudio();

    void playSfx(std::uint16_t id) override;
    void playBgm(std::uint16_t id) override;
    void stopBgm() override;

    // SDカードストリーミング再生の状態を更新（毎フレーム呼び出す）
    void update();

private:
    shiori::audio::ImaAdpcmDecoder m_decoder;  // フラッシュ常駐SEデコーダ

    // SDカードストリーミング用（スタブ）
    bool m_sd_initialized = false;             // SDカード初期化済みフラグ
    std::uint16_t m_bgm_id = 0;                // 現在再生中のBGM ID
    bool m_bgm_playing = false;                // BGM再生中フラグ
};

#endif // SHIORI_PLATFORM_GAMEBUINO_GBAUDIO_HPP
