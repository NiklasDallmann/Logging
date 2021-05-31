cmake_minimum_required(VERSION 3.15)

project(logging)

list(
	APPEND CMAKE_MODULE_PATH
	${CMAKE_CURRENT_LIST_DIR}/cmake)

include(ProjectSetup)
include(FetchContent)

make_compiler_flags(FLAGS)

FetchContent_Declare(
	fmt
	GIT_REPOSITORY	https://github.com/fmtlib/fmt
	SOURCE_DIR		${3RDPARTY_DIR}/fmt)
	
FetchContent_GetProperties(fmt)

if(NOT fmt_POPULATED)
	FetchContent_Populate(fmt)

	add_subdirectory(${fmt_SOURCE_DIR})
endif()

add_library(
	${PROJECT_NAME}
	# Header									Implementation
	${INCLUDE_DIR}/logging.hpp					${SOURCE_DIR}/logging.cpp)
add_library(nd::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
target_include_directories(
	${PROJECT_NAME}
	PUBLIC
	${INCLUDE_DIR})
target_link_libraries(
	${PROJECT_NAME}
	PUBLIC
	fmt::fmt)
target_compile_options(
	${PROJECT_NAME}
	PUBLIC
	${FLAGS})

enable_testing()

make_test(basic_test nd::logging)
