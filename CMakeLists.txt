cmake_minimum_required(VERSION 3.10)
SET(PROJ_NAME BoxesAndLines)
PROJECT(${PROJ_NAME})


enable_language(ASM)
set(CMAKE_CXX_COMPILER /usr/bin/clang++-12)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_ASM_COMPILER /usr/bin/clang++-12)
set(CMAKE_VERBOSE_MAKEFILE on)



find_package(Threads REQUIRED)

include_directories(
	"include/"
)


set(SRC_FILES



)



ADD_EXECUTABLE(BoxesAndLines main.cpp "${SRC_FILES}")


target_link_libraries(BoxesAndLines Threads::Threads)