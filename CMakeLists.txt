cmake_minimum_required(VERSION 3.10)
project(shiori VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 警告を厳しく扱う（Gamebuino 側と合わせる）。
if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -Werror)
endif()

# インクルードパス（リポジトリルートを基準とする）。
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# PC 用実行ファイル。
add_executable(shiori_pc
    platform/pc/main.cpp
    platform/pc/PcDisplay.cpp
    platform/pc/PcInput.cpp
    platform/pc/PcAudio.cpp
    platform/pc/PcTimer.cpp
    platform/pc/PcStorage.cpp
)

# TODO(ryo): core に実装が追加されたら、対応するソースファイルをここに追加する。
# 例:
#   core/world/Map.cpp
#   core/battle/Battle.cpp
#   core/story/Story.cpp
#   core/save/Bookmark.cpp
#   core/ai/Ai.cpp
