cmake_minimum_required(VERSION 3.0)
set (CMAKE_CXX_STANDARD 17)

project (TradingBot)

set(
	CMAKE_EXPORT_COMPILE_COMMANDS
	1
)

file(COPY ${CMAKE_SOURCE_DIR}/input DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${CMAKE_SOURCE_DIR}/config DESTINATION ${CMAKE_BINARY_DIR})

include_directories(${CMAKE_SOURCE_DIR}/src)

file (
    GLOB_RECURSE
    SOURCES
    #main
    ${CMAKE_SOURCE_DIR}/src/*.cpp
)
    
message("SOURCES = ${SOURCES}")

find_package(yaml-cpp REQUIRED)

message("INCLUDE ${YAML_CPP_INCLUDE_DIR}")
include_directories(${YAML_CPP_INCLUDE_DIR})

add_executable(bot ${SOURCES})
target_link_libraries(bot yaml-cpp)
