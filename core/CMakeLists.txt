project(core)

add_executable(core
            main.cpp
            )

target_link_libraries(core
            ${SDL2_LIBRARY}
            ${SDL2_IMAGE_LIBRARY}
            ${SDL2_TTF_LIBRARY}
#            ${TMXLITE_LIBRARY}
            )

install(TARGETS core RUNTIME DESTINATION ${BIN_DIR})
