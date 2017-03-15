project(bbstream)

cmake_minimum_required(VERSION 3.6)

add_definitions(-DCURL_STATICLIB)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DCURL_STATICLIB")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(CURL_STATICLIB ON CACHE BOOL "Enable static lib")
#set(BUILD_CPR_TESTS OFF)

file(GLOB_RECURSE bbstream_SRC
  "src/*.cpp"
)

file(GLOB_RECURSE bbstream_HEADER
  "include/*.h"
)

include_directories("core/include")
include_directories("externals/tinyxml2")

add_executable(${PROJECT_NAME} ${bbstream_SRC} ${bbstream_HEADER})

#set(BUILD_TESTING OFF)
add_subdirectory(externals/cpr)
#cpr_option(BUILD_CPR_TESTS "Set to ON to build cpr tests." OFF)
#option(BUILD_TESTING "gg" OFF)
#set(BUILD_TESTING OFF)

add_subdirectory(core)

target_link_libraries(bbstream bbstream_core ${CPR_LIBRARIES} ${CURL_LIBRARY})	

add_custom_command(TARGET bbstream POST_BUILD COMMAND ${CMAKE_COMMAND}  -E copy $<TARGET_FILE:bbstream_core> "$<TARGET_FILE_DIR:bbstream>/$<TARGET_FILE_NAME:bbstream_core>")
