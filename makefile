#CXX      =  clang++
CXX       =  g++
CXXFLAGS  = -Iinclude -std=c++20
LDFLAGS   = -lraylib -lm -lpthread
BIN       = -o bin/app
OBJ       = obj
OBJS       = $(patsubst src/%.cpp, obj/%.o, $(wildcard src/*.cpp))

obj/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

all: $(OBJS)
	$(CXX) $(CXXFLAGS) main.cpp $^ $(BIN) $(LDFLAGS)

preprocessor: $(OBJS)
	$(CXX) $(CXXFLAGS) -E main.cpp $^ $(BIN) $(LDFLAGS)

debug: $(OBJS)
	$(CXX) $(CXXFLAGS) -ggdb main.cpp $^ $(BIN) $(LDFLAGS)

release: CXXFLAGS= -Iinclude -Wall -O3 -DNDEBUG
release: all

clean:
	rm obj/*
	rm bin/*

