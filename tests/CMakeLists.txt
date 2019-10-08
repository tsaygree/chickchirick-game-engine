project(tests)

set(CORE_DIR ${chickchirik-game-engine_SOURCE_DIR}/core)

add_executable(
	tests
    tests.cpp
	${CORE_DIR}/Allocators/BlockAlloc.cpp
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
	${CORE_DIR}
	cases
)
