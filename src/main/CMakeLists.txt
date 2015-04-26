AUX_SOURCE_DIRECTORY (src SRCS)
add_executable (scop ${SRCS})

find_package(OpenGL REQUIRED)

INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)

# Make sure the compiler can find include files
target_include_directories (scop PUBLIC inc)
