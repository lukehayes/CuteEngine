CC      =  clang++
#CC      =  g++
CFLAGS  = -Iinclude -Iinclude/raylib-cpp
LDFLAGS = -lraylib -lm -lpthread
BIN     = -o bin/app
OBJ     = obj
OBJS    = $(patsubst src/%.cpp, obj/%.o, $(wildcard src/*.cpp))

obj/%.o: src/%.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(OBJS)
	$(CC) $(CFLAGS) main.cpp $^ $(BIN) $(LDFLAGS)

preprocessor: $(OBJS)
	$(CC) $(CFLAGS) -E main.cpp $^ $(BIN) $(LDFLAGS)

debug: $(OBJS)
	$(CC) $(CFLAGS) -ggdb main.cpp $^ $(BIN) $(LDFLAGS)

release: CFLAGS= -Iinclude -Wall -O3 -DNDEBUG
release: all

clean:
	rm obj/*
	rm bin/*

