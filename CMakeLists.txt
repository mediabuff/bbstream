project(bbstream)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

file(GLOB_RECURSE bbstream_SRC
  "src/*.cpp"
)

file(GLOB_RECURSE bbstream_HEADER
  "include/*.h"
)

add_executable(${PROJECT_NAME} ${bbstream_SRC} ${bbstream_HEADER})
