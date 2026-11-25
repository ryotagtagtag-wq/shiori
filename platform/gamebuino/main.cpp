// Gamebuino META エントリポイント（Arduino）。未完了。
// TODO(ryo): Gamebuino-META の setup/loop と core ゲームロジックを組み立てる。

#include "platform/gamebuino/GbDisplay.hpp"
#include "platform/gamebuino/GbInput.hpp"
#include "platform/gamebuino/GbAudio.hpp"
#include "platform/gamebuino/GbTimer.hpp"
#include "platform/gamebuino/GbStorage.hpp"

namespace shiori::platform::gamebuino {

static GbDisplay display;
static GbInput input;
static GbAudio audio;
static GbTimer timer;
static GbStorage storage;

} // namespace shiori::platform::gamebuino

extern "C" {

void setup() {
    using namespace shiori::platform::gamebuino;
    display.clear();
    input.update();
}

void loop() {
    using namespace shiori::platform::gamebuino;
    timer.beginFrame();
    input.update();
    display.clear();
    display.present();
    timer.endFrame();
}

} // extern "C"
