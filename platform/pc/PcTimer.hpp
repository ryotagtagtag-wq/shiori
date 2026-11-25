#ifndef SHIORI_PLATFORM_PC_PCTIMER_HPP
#define SHIORI_PLATFORM_PC_PCTIMER_HPP

#include <chrono>

#include "hal/ITimer.hpp"

namespace shiori::platform::pc {

// PC 向けタイマ実装。std::chrono を使用する。
class PcTimer : public hal::ITimer {
public:
    PcTimer();

    std::uint32_t getTicks() const override;
    std::uint32_t getDeltaTicks() const override;
    void beginFrame() override;
    void endFrame() override;

private:
    using Clock = std::chrono::steady_clock;
    Clock::time_point m_start;
    Clock::time_point m_frameStart;
    std::uint32_t m_deltaTicks = 0;
};

} // namespace shiori::platform::pc

#endif // SHIORI_PLATFORM_PC_PCTIMER_HPP
