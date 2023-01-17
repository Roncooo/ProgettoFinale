cmake_minimum_required(VERSION 2.9)

project(BattagliaNavale)

include_directories(
	include
)

set(SOURCES
	src/Ship.cpp
	src/Match.cpp
	src/Player.cpp
	src/Position.cpp
	src/Grid.cpp
	src/AttackGrid.cpp
	src/DefenceGrid.cpp
	src/Battleship.cpp
	src/Support.cpp
	src/Submarine.cpp
	src/Log.cpp
	src/replay.cpp
)

add_library(my_lib
	${SOURCES}
)

add_executable(battaglia_navale 
	src/main.cpp
)

target_link_libraries(battaglia_navale
	my_lib
)

add_executable(replay 
	src/replay.cpp
)

target_link_libraries(replay
	my_lib
)