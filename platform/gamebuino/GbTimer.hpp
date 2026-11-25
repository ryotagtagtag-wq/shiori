#ifndef SHIORI_PLATFORM_GAMEBUINO_GBTIMER_HPP
#define SHIORI_PLATFORM_GAMEBUINO_GBTIMER_HPP

#include "hal/ITimer.hpp"

// Gamebuino META 向けタイマ実装。未完了。
// TODO(ryo): millis() 等を使って実装する。
class GbTimer : public shiori::hal::ITimer {
public:
    std::uint32_t getTicks() const override;
    std::uint32_t getDeltaTicks() const override;
    void beginFrame() override;
    void endFrame() override;
};

#endif // SHIORI_PLATFORM_GAMEBUINO_GBTIMER_HPP
