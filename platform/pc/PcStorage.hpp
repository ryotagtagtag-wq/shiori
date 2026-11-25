#ifndef SHIORI_PLATFORM_PC_PCSTORAGE_HPP
#define SHIORI_PLATFORM_PC_PCSTORAGE_HPP

#include <array>
#include <cstddef>
#include <cstdint>

#include "hal/IStorage.hpp"

namespace shiori::platform::pc {

// PC 向けストレージ実装。メモリ上の固定長バッファで栞を模倣する。
// TODO(ryo): 実際のファイル/EEPROM への読み書きに差し替える。
class PcStorage : public hal::IStorage {
public:
    PcStorage();

    bool load(std::uint8_t slot, void* buffer, std::size_t size) override;
    bool save(std::uint8_t slot, const void* buffer, std::size_t size) override;
    bool exists(std::uint8_t slot) const override;

private:
    static constexpr std::size_t kSlotSize = 64;
    std::array<std::array<std::uint8_t, kSlotSize>, 16> m_slots{};
    std::array<bool, 16> m_used{};
};

} // namespace shiori::platform::pc

#endif // SHIORI_PLATFORM_PC_PCSTORAGE_HPP
