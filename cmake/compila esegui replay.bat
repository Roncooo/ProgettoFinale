cd cmake
cmake . -G"MinGW Makefiles" -B build-config && cmake --build build-config
cd build-config
replay.exe
pause