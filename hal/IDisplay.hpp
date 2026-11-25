#ifndef SHIORI_HAL_IDISPLAY_HPP
#define SHIORI_HAL_IDISPLAY_HPP

#include <cstdint>

namespace shiori::hal {

// 画面描画の抽象インターフェース。
// プラットフォーム側（pc / gamebuino）で実装する。
class IDisplay {
public:
    virtual ~IDisplay() = default;

    // 画面をクリアする。
    virtual void clear() = 0;

    // タイルを描画する。(x, y) はピクセル座標。
    virtual void drawTile(std::int16_t x, std::int16_t y, std::uint16_t tileId) = 0;

    // スプライトを描画する。(x, y) はピクセル座標。
    virtual void drawSprite(std::int16_t x, std::int16_t y, std::uint16_t spriteId) = 0;

    // 描画内容を画面に確定させる（1 フレーム分）。
    virtual void present() = 0;
};

} // namespace shiori::hal

#endif // SHIORI_HAL_IDISPLAY_HPP
