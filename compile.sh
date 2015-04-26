cd src
mkdir cmake_output
# rm -rf *
cd cmake_output
cmake ../ 
make
cd ../..
ln -fs src/cmake_output/main/scop scop
