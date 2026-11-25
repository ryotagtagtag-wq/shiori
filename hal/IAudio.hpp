#ifndef SHIORI_HAL_IAUDIO_HPP
#define SHIORI_HAL_IAUDIO_HPP

#include <cstdint>

namespace shiori::hal {

// 音声再生の抽象インターフェース。
// 未実装のプラットフォームでは no-op で構わない。
class IAudio {
public:
    virtual ~IAudio() = default;

    // 効果音を再生する。
    virtual void playSfx(std::uint16_t id) = 0;

    // BGM を再生する。
    virtual void playBgm(std::uint16_t id) = 0;

    // BGM を停止する。
    virtual void stopBgm() = 0;
};

} // namespace shiori::hal

#endif // SHIORI_HAL_IAUDIO_HPP
