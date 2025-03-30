cmake_minimum_required(VERSION 3.25)
project(cdatastructure VERSION 0.1 LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_EXTENSIONS off)
set(SRC_DIR src)

add_library(${PROJECT_NAME} INTERFACE ${SRC_DIR})
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
	target_compile_options(${PROJECT_NAME} INTERFACE /W4 /WX)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
	target_compile_options(${PROJECT_NAME} INTERFACE -Wall -Wextra -pedantic)
endif()

set(TEST_ROOT_DIR test)
set(TEST_EXE cdatastructuretest)
add_executable(${TEST_EXE} ${TEST_ROOT_DIR}/main.c ${TEST_ROOT_DIR}/int_p_linked_list.c ${TEST_ROOT_DIR}/struct_test_ll.c)
target_include_directories(${TEST_EXE} PRIVATE ${SRC_DIR})
target_link_libraries(${TEST_EXE} ${PROJECT_NAME})