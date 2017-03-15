project(bbstream_core)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

file(GLOB_RECURSE bbstream_core_SRC
  "src/*.cpp"
)

file(GLOB_RECURSE bbstream_core_HEADER
  "include/bbstream/*.h"
)

set(TINYXML2 "../externals/tinyxml2/tinyxml2.cpp" "../externals/tinyxml2/tinyxml2.h")

set(EXTERNAL_DEPENDENCIES ${TINYXML2})

include_directories(${CURL_INCLUDE_DIR})
include_directories(${CPR_INCLUDE_DIRS})

add_library(${PROJECT_NAME} SHARED ${bbstream_core_SRC} ${bbstream_core_HEADER} ${EXTERNAL_DEPENDENCIES})

target_link_libraries(bbstream_core ${CURL_LIBRARY} ${CPR_LIBRARIES})