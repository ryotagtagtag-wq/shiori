#ifndef SHIORI_HAL_ITIMER_HPP
#define SHIORI_HAL_ITIMER_HPP

#include <cstdint>

namespace shiori::hal {

// 時間計測・フレーム制御の抽象インターフェース。
class ITimer {
public:
    virtual ~ITimer() = default;

    // 起動からの経過ミリ秒を返す。
    virtual std::uint32_t getTicks() const = 0;

    // 前フレーム以降の経過ミリ秒（デルタタイム）を返す。
    virtual std::uint32_t getDeltaTicks() const = 0;

    // フレーム開始を通知する。
    virtual void beginFrame() = 0;

    // フレーム終了を通知する（必要に応じてウェイトする）。
    virtual void endFrame() = 0;
};

} // namespace shiori::hal

#endif // SHIORI_HAL_ITIMER_HPP
