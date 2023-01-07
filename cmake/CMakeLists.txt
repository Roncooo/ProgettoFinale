cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 11)

project(ProgettoFinale)

include_directories(include)

add_executable(battaglia_navale 
	src/main.cpp
)

set(HEADERS
	include/Grid.h
	include/DefenceGrid.h
	include/AttackGrid.h
	include/Position.h
	include/Ship.h
	include/Battleship.h
	include/Support.h
	include/Submarine.h
	include/Match.h
	include/Player.h
)

set(SOURCES
	src/Match.cpp
	src/Player.cpp
	src/Position.cpp
	src/Grid.cpp
	src/AttackGrid.cpp
	src/DefenceGrid.cpp
	src/Ship.cpp
	src/Battleship.cpp
	src/Support.cpp
	src/Submarine.cpp
)

add_library(battaglia_navale_lib
	${SOURCES}
	${HEADERS}
)

target_link_libraries(battaglia_navale 
	battaglia_navale_lib
)
