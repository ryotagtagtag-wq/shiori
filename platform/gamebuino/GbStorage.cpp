#include "platform/gamebuino/GbStorage.hpp"

// TODO(ryo): Gamebuino-META EEPROM/フラッシュ実装。
bool GbStorage::load(std::uint8_t, void*, std::size_t) { return false; }
bool GbStorage::save(std::uint8_t, const void*, std::size_t) { return false; }
bool GbStorage::exists(std::uint8_t) const { return false; }
