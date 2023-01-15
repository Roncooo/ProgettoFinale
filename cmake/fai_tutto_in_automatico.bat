cd ..
mkdir cmake\src
mkdir cmake\include
copy Progetto\*.cpp cmake\src
copy Progetto\*.h cmake\include
cd cmake
cmake . -G"MinGW Makefiles" -B build-config && cmake --build build-config
cd build-config
eseguibile.exe
pause
