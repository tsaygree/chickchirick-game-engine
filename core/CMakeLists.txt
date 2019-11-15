project(core)

add_executable(
	core
	${CORE_SOURCES}
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
	InputModule/InputDevice
	InputModule/Gamepad
	EventModule/EventLoop
	EventModule/Event
	Timer
)
