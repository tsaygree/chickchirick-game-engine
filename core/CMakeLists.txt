project(core)

add_executable(
	core
	${CORE_CPP}
)

target_link_libraries(
	core
    ${DEP_LIBS}
	${Boost_LIBRARIES}
)

install(TARGETS core RUNTIME DESTINATION ${BIN_DIR})
