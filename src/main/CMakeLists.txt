AUX_SOURCE_DIRECTORY (src SRCS)
add_executable (scop ${SRCS})

# Make sure the compiler can find include files
target_include_directories (scop PUBLIC inc)
