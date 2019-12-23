project(core)

add_executable(
	core
	${CORE_CPP}
)

target_link_libraries(
	core
  	${DEP_LIBS}
	${SDL2_LIBS}
	${SDL2_IMAGE_LIBRARY}
	${SDL2_TTF_LIBRARY}
	${Boost_LIBRARIES}
)

install(TARGETS core RUNTIME DESTINATION ${BIN_DIR})
