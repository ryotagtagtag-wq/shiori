#ifndef SHIORI_PLATFORM_GAMEBUINO_GBINPUT_HPP
#define SHIORI_PLATFORM_GAMEBUINO_GBINPUT_HPP

#include "hal/IInput.hpp"

// Gamebuino META 向け入力実装。未完了。
// TODO(ryo): Gamebuino-META のボタン状態を読む実装に差し替える。
class GbInput : public shiori::hal::IInput {
public:
    void update() override;
    bool pressed(shiori::hal::Button b) const override;
    bool triggered(shiori::hal::Button b) const override;
    bool released(shiori::hal::Button b) const override;
};

#endif // SHIORI_PLATFORM_GAMEBUINO_GBINPUT_HPP
