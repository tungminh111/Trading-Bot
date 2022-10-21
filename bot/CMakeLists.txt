cmake_minimum_required(VERSION 3.0)
set (CMAKE_CXX_STANDARD 11)

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
SUBDIRLIST(SUBDIRS src)
SUBDIRLIST(SUBDIRS build)

include_directories(${CMAKE_SOURCE_DIR}/build/lib/src/yaml-cpp/include)
file(GLOB LIBRARIES "${CMAKE_SOURCE_DIR}/build/lib/src/yaml-cpp-build/*.dylib")
message("LIBRARIES = ${LIBRARIES}")

add_executable(bot src/main.cpp)
target_link_libraries(bot ${LIBRARIES})
