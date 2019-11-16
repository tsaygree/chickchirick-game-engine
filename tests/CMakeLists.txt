project(tests)

add_executable(
	tests
    tests.cpp
	cases/BlockAllocTests.cpp
	cases/StackAllocTests.cpp
	cases/MemoryUnitsTests.cpp
	cases/StringIDTests.cpp
	cases/MemorySystemTests.cpp
	${CORE_DIR}/Allocators/BlockAlloc.cpp
	${CORE_DIR}/Allocators/StackAlloc.cpp
	${CORE_DIR}/AssetManager/AssetManager.cpp
	${CORE_DIR}/FileSystem/FileSystem.cpp
	${CORE_DIR}/StringID/StringID.cpp
	${CORE_DIR}/SystemManager/SystemManager.cpp
	${CORE_DIR}/MemorySystem/MemorySystem.cpp
	${CORE_DIR}/ConfigManager/ConfigManager.cpp
	${CORE_DIR}/SDLModule/SDLModule.cpp
	${CORE_DIR}/Asset/Map/Map.cpp
	${CORE_DIR}/GameLoop/GameLoop.cpp
	${CORE_DIR}/GameObject/GameObject.cpp
	${CORE_DIR}/InputModule/Command/Command.cpp
	${CORE_DIR}/InputModule/InputHandler/InputHandler.cpp
	${CORE_DIR}/InputModule/Gamepad/Gamepad.cpp
	${CORE_DIR}/EventModule/EventLoop/EventLoop.cpp
	${CORE_DIR}/EventModule/Event/Event.cpp
	${CORE_DIR}/Timer/Timer.cpp
)

target_link_libraries(
	tests
    ${SDL2_LIBRARY}
    ${SDL2_IMAGE_LIBRARY}
    ${SDL2_TTF_LIBRARY}
    ${TMXLITE_LIBRARY}
)

install(TARGETS tests RUNTIME DESTINATION ${BIN_DIR})
