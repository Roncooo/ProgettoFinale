cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 11)

project(ProgettoFinale)

include_directories(include)

add_executable(BattagliaNavale 
	src/main.cpp
)

add_library(Grid
	include/Grid.h
	src/Grid.cpp
	include/DefenceGrid.h
	src/DefenceGrid.cpp
	include/AttackGrid.h
	src/AttackGrid.cpp
	include/Position.h
	src/Position.cpp
)

add_library(Ship
	include/Ship.h
	src/Ship.cpp
	include/Battleship.h
	src/Battleship.cpp
	include/Support.h
	src/Support.cpp
	include/Submarine.h
	src/Submarine.cpp
)

add_library(Match
	include/Match.h
	src/Match.cpp
)

add_library(Player
	include/Player.h
	src/Player.cpp
)

target_link_libraries(BattagliaNavale 
	Grid
	Ship
	Match
	Player
)
