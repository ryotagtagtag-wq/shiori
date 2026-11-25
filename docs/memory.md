# RAM / フラッシュ使用量記録

実機（Gamebuino META）公称値: RAM 32KB / フラッシュ 256KB。
70% 超過（RAM 22.4KB 超）で実装を止めて Ryo に報告すること。

## 計測記録

| 日付 | 項目 | RAM | フラッシュ | 備考 | 担当 |
|---|---|---|---|---|---|
| 2026-11-25 | 初期スキャフォールド | 未計測 | 未計測 | PC ビルド成功（g++ -Wall -Wextra -Werror、警告ゼロ）。arm-none-eabi-size 未導入のため実機計測は未実施 | impl |
| 2026-11-25 | ゲームブーノスタブ (pio build, arduino_zero/adafruit_metro_m0 代用) | 2648 bytes (8.1%) | 11244 bytes (4.3%) | pio run -e gamebuino_meta 成功。70% 閾値を大幅に下回る | impl |
