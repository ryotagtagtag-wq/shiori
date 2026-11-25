#ifndef SHIORI_HAL_IINPUT_HPP
#define SHIORI_HAL_IINPUT_HPP

#include <cstdint>

namespace shiori::hal {

// 入力ボタンの種類。
enum class Button : std::uint8_t {
    Up,
    Down,
    Left,
    Right,
    A,
    B,
    Menu,
    Count, // ボタン総数（番兵）
};

// 入力状態の抽象インターフェース。
// 押下中 / 押下（ワンフレーム） / 離上 の 3 状態を区別して取得する。
class IInput {
public:
    virtual ~IInput() = default;

    // フレームごとの状態を更新する。各プラットフォームの更新ループで呼ぶ。
    virtual void update() = 0;

    // 指定ボタンが押下中か。
    virtual bool pressed(Button b) const = 0;

    // 指定ボタンがこのフレームに新たに押下されたか。
    virtual bool triggered(Button b) const = 0;

    // 指定ボタンがこのフレームに離されたか。
    virtual bool released(Button b) const = 0;
};

} // namespace shiori::hal

#endif // SHIORI_HAL_IINPUT_HPP
