#include "core/fixed.hpp"
#include "core/config.hpp"

#include "platform/pc/PcDisplay.hpp"
#include "platform/pc/PcInput.hpp"
#include "platform/pc/PcAudio.hpp"
#include "platform/pc/PcTimer.hpp"
#include "platform/pc/PcStorage.hpp"

#include <cstdint>
#include <cstdio>

namespace {

using namespace shiori;
using namespace shiori::platform::pc;

// ゲームの組み立て。core + platform のみを結合し、ゲームループを回す。
int run() {
    PcDisplay display;
    PcInput input;
    PcAudio audio;
    PcTimer timer;
    PcStorage storage;

    bool running = true;
    std::int32_t frameLimit = 120; // スタブ: 120 フレームで終了（実機ではゲームループ）
    while (running && frameLimit-- > 0) {
        timer.beginFrame();
        input.update();

        if (input.triggered(hal::Button::B)) {
            running = false;
        }

        display.clear();
        // TODO(ryo): core のゲームロジック（ワールド、物語、戦闘）をここで更新・描画する。
        display.present();

        timer.endFrame();

        // 60 FPS 目安の簡易ウェイト（スタブ）。
        if (timer.getDeltaTicks() < 16) {
            // TODO(ryo): プラットフォーム依らずのフレーム制御を ITimer に委譲する。
        }
    }

    return 0;
}

} // namespace

int main() {
    std::printf("shiori (PC build) starting\n");
    std::printf("config::max_sprites = %u\n",
                static_cast<unsigned>(shiori::config::max_sprites));
    return run();
}
