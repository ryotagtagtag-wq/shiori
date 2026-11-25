#include "platform/pc/PcInput.hpp"

namespace shiori::platform::pc {

void PcInput::update() {
    // TODO(ryo): SDL2 イベントから m_state を更新する。
}

bool PcInput::pressed(hal::Button) const {
    return false;
}

bool PcInput::triggered(hal::Button) const {
    return false;
}

bool PcInput::released(hal::Button) const {
    return false;
}

} // namespace shiori::platform::pc
