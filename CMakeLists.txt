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

include_directories("core/include")

add_executable(${PROJECT_NAME} ${bbstream_SRC} ${bbstream_HEADER})

add_subdirectory(core)

target_link_libraries(bbstream bbstream_core)	

add_custom_command(TARGET bbstream POST_BUILD COMMAND ${CMAKE_COMMAND}  -E copy $<TARGET_FILE:bbstream_core> "$<TARGET_FILE_DIR:bbstream>/$<TARGET_FILE_NAME:bbstream_core>")