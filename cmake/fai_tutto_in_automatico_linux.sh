mkdir src
mkdir include
cd ..
cp Progetto/*.cpp cmake/src
cp Progetto/*.h cmake/include
cd cmake
cmake . -B build-config
cmake --build build-config
build-config/eseguibile
read