project(core)

add_executable(
	core
    main.cpp
	SystemManager/SystemManager.cpp
	FileSystem/FileSystem.cpp
	StringID/StringID.cpp
	ConfigManager/ConfigManager.cpp
)

target_link_libraries(
	core
    ${SDL2_LIBRARY}
    ${SDL2_IMAGE_LIBRARY}
    ${SDL2_TTF_LIBRARY}
#    ${TMXLITE_LIBRARY}
)

install(TARGETS core RUNTIME DESTINATION ${BIN_DIR})

include_directories(
	SystemManager
	StringID
	FileSystem
	ConfigManager
)
