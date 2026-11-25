#ifndef SHIORI_CORE_AUDIO_IMA_ADPCM_DECODER_HPP
#define SHIORI_CORE_AUDIO_IMA_ADPCM_DECODER_HPP

#include <cstdint>

namespace shiori::audio {

// IMA ADPCM ステップサイズテーブル (89エントリ)
constexpr std::int16_t ima_step_table[89] = {
    7, 8, 9, 10, 11, 12, 13, 14, 16, 17,
    19, 21, 23, 25, 28, 31, 34, 37, 41, 45,
    50, 55, 60, 66, 73, 80, 88, 97, 107, 118,
    130, 143, 157, 173, 190, 209, 230, 253, 279, 307,
    337, 371, 408, 449, 494, 544, 598, 658, 724, 796,
    876, 963, 1060, 1166, 1282, 1411, 1552, 1707, 1878, 2066,
    2272, 2499, 2749, 3024, 3327, 3660, 4026, 4428, 4871, 5358,
    5894, 6484, 7132, 7845, 8630, 9493, 10442, 11487, 12635, 13899,
    15289, 16818, 18500, 20350, 22385, 24623, 27086, 29794, 32767,
};

// 各ステップに対するインデックス調整値
constexpr std::int8_t ima_index_adjust[8] = {-1, -1, -1, -1, 2, 4, 6, 8};

// 1サンプルあたりのバッファ最大サイズ（デコード済みPCMサンプルを蓄積）
constexpr std::uint16_t ima_adpcm_max_buffer_samples = 1024;

// IMA ADPCM デコーダ。
// 圧縮データから1バイト（2サンプル）ずつPCMサンプルを復元する。
// 動的確保を行わないため、すべて固定長メンバーとする。
class ImaAdpcmDecoder {
public:
    ImaAdpcmDecoder() = default;

    // デコーダを初期状態に戻す。
    void reset() {
        m_predictor = 0;
        m_step_index = 0;
        m_step = ima_step_table[0];
        m_sample_count = 0;
    }

    // 1バイト（2サンプル）をデコードし、結果を内部バッファに蓄積する。
    // 戻り値: デコードしたサンプル数（0, 1, または 2）
    std::uint8_t decodeByte(std::uint8_t byte) {
        // 上位4bitと下位4bitの2サンプルをデコード
        const std::uint8_t high_nibble = (byte >> 4) & 0x0F;
        const std::uint8_t low_nibble = byte & 0x0F;

        std::uint8_t count = 0;
        if (m_sample_count < ima_adpcm_max_buffer_samples) {
            m_samples[m_sample_count] = decodeNibble(high_nibble);
            ++m_sample_count;
            ++count;
        }
        if (m_sample_count < ima_adpcm_max_buffer_samples) {
            m_samples[m_sample_count] = decodeNibble(low_nibble);
            ++m_sample_count;
            ++count;
        }
        return count;
    }

    // デコード済みサンプル数を取得する。
    std::uint16_t sampleCount() const {
        return m_sample_count;
    }

    // 指定インデックスのデコード済みサンプルを取得する。
    std::int16_t getSample(std::uint16_t index) const {
        if (index < m_sample_count) {
            return m_samples[index];
        }
        return 0;
    }

    // デコード済みサンプルをすべて消費（クリア）する。
    void clear() {
        m_sample_count = 0;
    }

private:
    // 4bitコードワードから1サンプルをデコードする。
    std::int16_t decodeNibble(std::uint8_t code) {
        const std::int8_t sign = (code & 0x08) ? -1 : 1;
        const std::uint8_t magnitude = code & 0x07;

        // 差分を計算: (2 * magnitude + 1) * step / 8
        const std::int32_t diff =
            (static_cast<std::int32_t>(2 * magnitude + 1) * static_cast<std::int32_t>(m_step)) / 8;

        // 予測値を更新
        std::int32_t new_predictor = static_cast<std::int32_t>(m_predictor) + sign * diff;
        if (new_predictor > 32767) {
            new_predictor = 32767;
        }
        if (new_predictor < -32768) {
            new_predictor = -32768;
        }
        m_predictor = static_cast<std::int16_t>(new_predictor);

        // ステップインデックスを更新
        std::int32_t new_index =
            static_cast<std::int32_t>(m_step_index) + static_cast<std::int32_t>(ima_index_adjust[magnitude]);
        if (new_index < 0) {
            new_index = 0;
        }
        if (new_index > 88) {
            new_index = 88;
        }
        m_step_index = static_cast<std::uint8_t>(new_index);
        m_step = ima_step_table[m_step_index];

        return m_predictor;
    }

    std::int16_t m_predictor = 0;          // 現在の予測値
    std::uint8_t m_step_index = 0;         // 現在のステップインデックス
    std::int16_t m_step = ima_step_table[0];  // 現在のステップサイズ
    std::int16_t m_samples[ima_adpcm_max_buffer_samples] = {}; // デコード済みサンプルバッファ
    std::uint16_t m_sample_count = 0;      // バッファ内のサンプル数
};

} // namespace shiori::audio

#endif // SHIORI_CORE_AUDIO_IMA_ADPCM_DECODER_HPP
