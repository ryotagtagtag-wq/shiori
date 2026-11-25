#ifndef SHIORI_PLATFORM_GAMEBUINO_GBSTORAGE_HPP
#define SHIORI_PLATFORM_GAMEBUINO_GBSTORAGE_HPP

#include "hal/IStorage.hpp"

// Gamebuino META 向けストレージ実装（EEPROM / フラッシュ）。未完了。
// TODO(ryo): Gamebuino-META の保存領域に差し替える。書き込み回数に注意。
class GbStorage : public shiori::hal::IStorage {
public:
    bool load(std::uint8_t slot, void* buffer, std::size_t size) override;
    bool save(std::uint8_t slot, const void* buffer, std::size_t size) override;
    bool exists(std::uint8_t slot) const override;
};

#endif // SHIORI_PLATFORM_GAMEBUINO_GBSTORAGE_HPP
