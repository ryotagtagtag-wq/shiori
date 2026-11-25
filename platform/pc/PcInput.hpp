#ifndef SHIORI_PLATFORM_PC_PCINPUT_HPP
#define SHIORI_PLATFORM_PC_PCINPUT_HPP

#include "hal/IInput.hpp"

namespace shiori::platform::pc {

// PC 向け入力実装。SDL2 イベントポーリングは未統合。
class PcInput : public hal::IInput {
public:
    void update() override;
    bool pressed(hal::Button b) const override;
    bool triggered(hal::Button b) const override;
    bool released(hal::Button b) const override;
};

} // namespace shiori::platform::pc

#endif // SHIORI_PLATFORM_PC_PCINPUT_HPP
