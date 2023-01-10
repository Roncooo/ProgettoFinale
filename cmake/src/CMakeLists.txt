include_directories(${PROJECT_SOURCE_DIR}/include/)

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

add_library(LibProject ${SOURCES})
add_executable(eseguibile main.cpp)
target_link_libraries(eseguibile LibProject)