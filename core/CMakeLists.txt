project(bbstream_core)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

file(GLOB_RECURSE bbstream_core_SRC
  "src/*.cpp"
)

file(GLOB_RECURSE bbstream_core_HEADER
  "include/*.h"
)

add_library(${PROJECT_NAME} SHARED ${bbstream_core_SRC} ${bbstream_core_HEADER})