project(tests)

add_executable(
	tests
    tests.cpp
	cases/BlockAllocTests.cpp
	cases/StackAllocTests.cpp
	cases/MemoryUnitsTests.cpp
	${CORE_DIR}/Allocators/BlockAlloc.cpp
	${CORE_DIR}/Allocators/StackAlloc.cpp
	${CORE_DIR}/AssetManager/AssetManager.cpp
	${CORE_DIR}/FileSystem/FileSystem.cpp
	${CORE_DIR}/StringID/StringID.cpp
	${CORE_DIR}/SystemManager/SystemManager.cpp
)

target_link_libraries(
	tests
    ${SDL2_LIBRARY}
    ${SDL2_IMAGE_LIBRARY}
    ${SDL2_TTF_LIBRARY}
    # ${TMXLITE_LIBRARY}
)

install(TARGETS tests RUNTIME DESTINATION ${BIN_DIR})

include_directories(
	${TEST_DIR}
	${CORE_DIR}
	${CORE_DIR}/Allocators
	${CORE_DIR}/AssetManager
	${CORE_DIR}/Containers/HashTable
	${CORE_DIR}/FileSystem
	${CORE_DIR}/Includes
	${CORE_DIR}/MemoryUnits
	${CORE_DIR}/StringID
	${CORE_DIR}/SystemManager
	cases
)
