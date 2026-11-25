#include "platform/pc/PcStorage.hpp"

#include <cstring>

namespace shiori::platform::pc {

PcStorage::PcStorage() {
    m_slots.fill({});
    m_used.fill(false);
}

bool PcStorage::load(std::uint8_t slot, void* buffer, std::size_t size) {
    if (slot >= m_slots.size() || !m_used[slot] || buffer == nullptr) {
        return false;
    }
    const std::size_t copySize = (size < kSlotSize) ? size : kSlotSize;
    std::memcpy(buffer, m_slots[slot].data(), copySize);
    return true;
}

bool PcStorage::save(std::uint8_t slot, const void* buffer, std::size_t size) {
    if (slot >= m_slots.size() || buffer == nullptr || size > kSlotSize) {
        return false;
    }
    std::memcpy(m_slots[slot].data(), buffer, size);
    m_used[slot] = true;
    return true;
}

bool PcStorage::exists(std::uint8_t slot) const {
    return slot < m_used.size() && m_used[slot];
}

} // namespace shiori::platform::pc
