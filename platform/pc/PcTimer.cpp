#include "platform/pc/PcTimer.hpp"

namespace shiori::platform::pc {

PcTimer::PcTimer() : m_start(Clock::now()), m_frameStart(Clock::now()) {}

std::uint32_t PcTimer::getTicks() const {
    return static_cast<std::uint32_t>(
        std::chrono::duration_cast<std::chrono::milliseconds>(Clock::now() - m_start).count());
}

std::uint32_t PcTimer::getDeltaTicks() const {
    return m_deltaTicks;
}

void PcTimer::beginFrame() {
    m_frameStart = Clock::now();
}

void PcTimer::endFrame() {
    const auto now = Clock::now();
    m_deltaTicks = static_cast<std::uint32_t>(
        std::chrono::duration_cast<std::chrono::milliseconds>(now - m_frameStart).count());
}

} // namespace shiori::platform::pc
