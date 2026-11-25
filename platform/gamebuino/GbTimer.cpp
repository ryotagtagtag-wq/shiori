#include "platform/gamebuino/GbTimer.hpp"

// TODO(ryo): Gamebuino-META millis() 実装。
std::uint32_t GbTimer::getTicks() const { return 0; }
std::uint32_t GbTimer::getDeltaTicks() const { return 0; }
void GbTimer::beginFrame() {}
void GbTimer::endFrame() {}
