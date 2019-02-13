project(BallsNBricks)

cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 14)

set(SFML_DIR "d:/devtools/mingw-w64/Libs/SFML-2.5.1/lib/cmake/SFML")
#set(CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules/")

find_package(SFML 2.4 COMPONENTS graphics audio REQUIRED)
add_executable(BallsNBricks src/game/Ball.cpp src/game/Brick.cpp src/game/Game.cpp src/game/GameObject.cpp src/game/LevelLoader.cpp src/game/Paddle.cpp src/BallsNBricks.cpp)


target_include_directories(BallsNBricks PRIVATE include)
target_link_libraries(BallsNBricks sfml-graphics)
