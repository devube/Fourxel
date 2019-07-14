SRC_CPP := $(shell find src/ -name '*.cpp')
SRC_C := $(shell find src/ -name '*.c')

all:
	g++ $(SRC_CPP) $(SRC_C) -lGL -o app -lglfw -I./include -I./src -I./modules
