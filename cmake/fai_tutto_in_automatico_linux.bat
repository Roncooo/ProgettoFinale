cd ..
mkdir cmake/src
mkdir cmake/include
cp Progetto/*.cpp cmake/src
cp Progetto/*.h cmake/include
cd cmake
cmake . -B build-config && cmake --build build-conftg
./eseguibile
read