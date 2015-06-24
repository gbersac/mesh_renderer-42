AUX_SOURCE_DIRECTORY (src SRCS)
add_executable (scop ${SRCS})

find_package(OpenGL REQUIRED)

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/sdl2/inc ${OPENGL_INCLUDE_DIR})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/sdl2/libSDL2.a  ${OPENGL_LIBRARIES})
MESSAGE("dump var : " ${CMAKE_SOURCE_DIR}/sdl2)

# Make sure the compiler can find include files
target_include_directories (scop PUBLIC inc)
