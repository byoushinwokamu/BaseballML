cmake_minimum_required(VERSION 3.22)

add_executable(
	main
	src/main.cc
	src/game.cc
	src/bot.cc
)
target_include_directories(
	main
	PUBLIC inc
)