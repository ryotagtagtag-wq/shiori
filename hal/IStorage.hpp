#ifndef SHIORI_HAL_ISTORAGE_HPP
#define SHIORI_HAL_ISTORAGE_HPP

#include <cstddef>
#include <cstdint>

namespace shiori::hal {

// 栞（セーブデータ）の読み書きの抽象インターフェース。
// 書き込み回数を抑えるため、書き込みは「栞を挟んだとき」のみに限定する。
class IStorage {
public:
    virtual ~IStorage() = default;

    // 指定スロットの栞を読み込む。成功したら true。
    virtual bool load(std::uint8_t slot, void* buffer, std::size_t size) = 0;

    // 指定スロットに栞を書き込む。成功したら true。
    virtual bool save(std::uint8_t slot, const void* buffer, std::size_t size) = 0;

    // 指定スロットが使用済みか。
    virtual bool exists(std::uint8_t slot) const = 0;
};

} // namespace shiori::hal

#endif // SHIORI_HAL_ISTORAGE_HPP
