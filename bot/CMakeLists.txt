cmake_minimum_required(VERSION 3.0)
set (CMAKE_CXX_STANDARD 17)

project (TradingBot)

set(
	CMAKE_EXPORT_COMPILE_COMMANDS
	1
)

include(ExternalProject)

ExternalProject_Add(yaml-cpp
	URL "https://github.com/jbeder/yaml-cpp/archive/refs/tags/yaml-cpp-0.7.0.zip"
	PREFIX lib 
	CMAKE_ARGS
	-DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
	-DYAML_BUILD_SHARED_LIBS="ON"
)


MACRO(SUBDIRLIST result curdir)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
      LIST(APPEND dirlist ${child})
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO()
include_directories(SUBDIRLIST(SUBDIRS src))
include_directories(SUBDIRLIST(SUBDIRS build))

include_directories(${CMAKE_SOURCE_DIR}/build/lib/src/yaml-cpp/include)
file(GLOB LIBRARIES "${CMAKE_SOURCE_DIR}/build/lib/src/yaml-cpp-build/*.dylib")
message("LIBRARIES = ${LIBRARIES}")

file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)
message("SOURCES = ${SOURCES}")

add_executable(bot ${SOURCES})
target_link_libraries(bot ${LIBRARIES})
