// Gamebuino META エントリポイント（Arduino）。core ゲームロジックを組み込み。
// TODO(ryo): Gamebuino-META の入力・描画・セーブと core ゲームロジックを連携させる。

#include "core/ai/AiManager.hpp"
#include "core/battle/BattleContext.hpp"
#include "core/story/StoryManager.hpp"
#include "core/world/World.hpp"

#include "platform/gamebuino/GbAudio.hpp"
#include "platform/gamebuino/GbDisplay.hpp"
#include "platform/gamebuino/GbInput.hpp"
#include "platform/gamebuino/GbStorage.hpp"
#include "platform/gamebuino/GbTimer.hpp"

namespace shiori::platform::gamebuino {

static GbDisplay display;
static GbInput input;
static GbAudio audio;
static GbTimer timer;
static GbStorage storage;

static world::World world;
static story::StoryManager story;
static ai::AiManager ai(story);
static battle::CombatantStats playerStats;
static battle::CombatantStats enemyStats;

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
    (void)world;
    (void)story;
    (void)ai;
    (void)playerStats;
    (void)enemyStats;
}

} // extern "C"
