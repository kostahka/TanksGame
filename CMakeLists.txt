cmake_minimum_required (VERSION 3.21)

project ("TanksGame" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

set(PROJECT_SOURCES
	"TanksGame.cpp"
	"GameObjects/Tank.cpp"
	"GameObjects/Bullet.cpp"
	"GameObjects/Gun.cpp"
	"GameObjects/Wall.cpp"
	"GameObjects/GameObject.cpp"
	"Scenes/Scene.cpp"
	"Scenes/GameScene.cpp"
	"General/Physics.cpp"
	"General/Map.cpp"
	"Controllers/PlayerController.cpp"
	"Controllers/Controller.cpp"
	"Configurations/Configure.cpp"
	"GameObjects/DynamicObject.cpp"
	"Managers/IOManager.cpp"
	"Managers/TimeManager.cpp"
	"Managers/TimeListener.cpp"
	"Animation/Animation.cpp"
	"Particles/Explosion.cpp"
	"Particles/Particles.cpp"

	"TanksGame.h"
	"GameObjects/Tank.h"
	"GameObjects/Bullet.h"
	"GameObjects/Gun.h"
	"GameObjects/Wall.h"
	"GameObjects/GameObject.h"
	"Configurations/Configure.h"
	"General/Direction.h"
	"Scenes/Scene.h" 
	"Scenes/GameScene.h"
	"General/Physics.h"
	"General/Map.h"
	"Controllers/PlayerController.h"
	"Controllers/Controller.h"
	"GameObjects/DynamicObject.h"
	"Managers/IOManager.h"
	"Managers/TimeManager.h"
	"Managers/TimeListener.h"
	"Animation/Animation.h"
	"Particles/Explosion.h"
	"Particles/Particles.h"

)

add_executable(game ${PROJECT_SOURCES})

add_custom_target(copy_resources ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/assets
        ${PROJECT_BINARY_DIR}/assets
        COMMENT "Copying resources into binary directory")

add_dependencies(game copy_resources)

set(SFML_STATIC_LIBRARIES TRUE)

target_link_libraries(game sfml-graphics sfml-system sfml-window)
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET game POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:game> $<TARGET_FILE_DIR:game> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS game)