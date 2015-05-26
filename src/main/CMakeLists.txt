AUX_SOURCE_DIRECTORY (src SRCS)
add_executable (scop ${SRCS})

find_package(OpenGL REQUIRED)

INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIR})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${OPENGL_LIBRARIES})
MESSAGE("dump var : " ${OPENGL_INCLUDE_DIR} ${OPENGL_LIBRARIES})

# Make sure the compiler can find include files
target_include_directories (scop PUBLIC inc)
