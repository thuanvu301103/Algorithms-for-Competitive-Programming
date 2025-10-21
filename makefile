# ==========================
# Makefile for building static library
# ==========================

# --------------------------
# Variables
# --------------------------
SRC := $(shell find src -name '*.cpp')           # All .cpp recursively
OBJ := $(patsubst src/%.cpp, build/%.o, $(SRC)) # Map src/*.cpp -> build/*.o
INCLUDE := -Iinclude
LIB := build/libcpalgorithm.a                   # Output static library
CXX := g++
CXXFLAGS := -Wall -Wextra -Wpedantic -g

# --------------------------
# Default target
# --------------------------
all: $(LIB)

# --------------------------
# Compile .cpp → .o
# --------------------------
build/%.o: src/%.cpp
	@mkdir -p $(dir $@)           # Tạo folder nếu chưa có
	$(CXX) $(CXXFLAGS) -c $< $(INCLUDE) -o $@

# --------------------------
# Create static library
# --------------------------
$(LIB): $(OBJ)
	@mkdir -p $(dir $@)
	ar rcs $@ $^

# --------------------------
# Clean build
# --------------------------
.PHONY: clean
clean:
	rm -rf build/*
