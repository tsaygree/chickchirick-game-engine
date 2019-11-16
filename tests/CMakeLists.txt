project(tests)

# Remove main.cpp from CORE_CPP source list to resolve duplicate main problem
set(CORE_CPP_NO_MAIN ${CORE_CPP})
list(REMOVE_ITEM CORE_CPP_NO_MAIN "${CORE_DIR}/main.cpp")

add_executable(
	tests
    ${TESTS_CPP}
	${CORE_CPP_NO_MAIN}
)

target_link_libraries(
	tests
    ${DEP_LIBS}
	${Boost_LIBRARIES}
)

install(TARGETS tests RUNTIME DESTINATION ${BIN_DIR})
