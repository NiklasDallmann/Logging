set(CMAKE_CXX_STANDARD
	17)

set(INCLUDE_DIR
	${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME})

set(SOURCE_DIR
	${CMAKE_CURRENT_SOURCE_DIR}/source)

set(TEST_DIR
	${CMAKE_CURRENT_SOURCE_DIR}/test)

set(3RDPARTY_DIR
	${CMAKE_CURRENT_SOURCE_DIR}/3rdparty)

mark_as_advanced(INCLUDE_DIR SOURCE_DIR TEST_DIR 3RDPARTY_DIR)

function(make_compiler_flags FLAGS)
	set(${FLAGS}
		"$<$<AND:$<CXX_COMPILER_ID:GNU>,$<CONFIG:RELEASE>>:SHELL:-O3 -march=native -mtune=native>"
		"$<$<AND:$<CXX_COMPILER_ID:GNU>,$<CONFIG:DEBUG>>:SHELL:-O0 -g>"
		PARENT_SCOPE)
endfunction()

macro(make_test TEST_NAME DEPENDENCIES)
	message("Creating test ${TEST_NAME} with ${TEST_DIR}/${TEST_NAME}.cpp")
	add_executable(
		${TEST_NAME}
		${TEST_DIR}/${TEST_NAME}.cpp)
	target_link_libraries(
		${TEST_NAME}
		${DEPENDENCIES})
	add_test(
		NAME ${TEST_NAME}
		COMMAND ${TEST_NAME})
endmacro()
