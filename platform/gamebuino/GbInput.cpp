#include "platform/gamebuino/GbInput.hpp"

// TODO(ryo): Gamebuino-META ボタン実装。
void GbInput::update() {}
bool GbInput::pressed(shiori::hal::Button) const { return false; }
bool GbInput::triggered(shiori::hal::Button) const { return false; }
bool GbInput::released(shiori::hal::Button) const { return false; }
