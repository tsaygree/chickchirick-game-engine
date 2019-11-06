project(core)

add_executable(
	core
    main.cpp
	SystemManager/SystemManager.cpp
	FileSystem/FileSystem.cpp
	StringID/StringID.cpp
	ConfigManager/ConfigManager.cpp
	Allocators/BlockAlloc.cpp
	Allocators/StackAlloc.cpp
	AssetManager/AssetManager.cpp
	MemorySystem/MemorySystem.cpp
	SDLModule/SDLModule.cpp
	Asset/Map/Map.cpp
	GameLoop/GameLoop.cpp
	GameObject/GameObject.cpp
	InputModule/Command/Command.cpp
	InputModule/InputHandler/InputHandler.cpp
	InputModule/Gamepad/Gamepad.cpp
	EventModule/EventLoop/EventLoop.cpp
)

target_link_libraries(
	core
    ${SDL2_LIBRARY}
    ${SDL2_IMAGE_LIBRARY}
    ${SDL2_TTF_LIBRARY}
    ${TMXLITE_LIBRARY}
)

install(TARGETS core RUNTIME DESTINATION ${BIN_DIR})

include_directories(
	Allocators
	AssetManager
	SystemManager
	StringID
	FileSystem
	ConfigManager
	Includes
	Containers/HashTable
	Containers/Vector
	Containers/PropertyTree
	MemorySystem
	SDLModule
	Asset
	Asset/Texture
	Asset/Map
	GameLoop
	GameObject
	InputModule/Command
	InputModule/InputHandler
	InputModule/Gamepad
	EventModule/EventLoop
)
