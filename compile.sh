cd src
mkdir compile
# rm -rf *
cd compile
cmake ../ 
make
cd ../..
ln -fs src/compile/main/scop scop
