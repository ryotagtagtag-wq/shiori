#ifndef SHIORI_CORE_CONFIG_HPP
#define SHIORI_CORE_CONFIG_HPP

#include <cstdint>

namespace shiori::config {

// ゲーム中に動的確保を行わないため、各プールの最大数をここで集約する。
// 実機の RAM 制約（公称 32KB）を考慮し控えめに設定する。

constexpr std::uint16_t max_tiles = 256;      // タイル定数の最大数
constexpr std::uint16_t max_sprites = 64;     // 同時表示スプライトの最大数
constexpr std::uint16_t max_map_width = 64;   // マップ幅最大（タイル単位）
constexpr std::uint16_t max_map_height = 64;  // マップ高最大（タイル単位）
constexpr std::uint16_t max_story_flags = 256;// 物語フラグの最大数
constexpr std::uint16_t max_bookmarks = 16;   // 栞（セーブスロット）の最大数
constexpr std::uint16_t max_choice_history = 64; // 選択履歴の最大数
constexpr std::uint16_t max_ai_history = 32;     // 案内人 AI が記録する履歴の最大数
constexpr std::uint16_t max_inventory_items = 8; // 所持品アイテムの最大数

} // namespace shiori::config

#endif // SHIORI_CORE_CONFIG_HPP
