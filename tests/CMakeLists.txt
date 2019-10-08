project(tests)

add_executable(
	tests
    tests.cpp
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
	cases
)
