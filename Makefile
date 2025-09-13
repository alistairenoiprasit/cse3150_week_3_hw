# AI DECLARATION: I USED AI TO CREATE THIS MAKE FILE
# I wanted to add leak sanitizer but had no idea
# so I used AI to simplify and automate the process for me

# Compiler
CXX = clang++
CXXFLAGS = -g -fsanitize=address -fno-omit-frame-pointer -std=c++17
SRC = solution.cpp
TARGET = gpa_test

# Default target: build
all: $(TARGET)

# Compile
$(TARGET):
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Run with optional arguments (pass via CMD)
run: $(TARGET)
	ASAN_OPTIONS=detect_leaks=1 ./$(TARGET) $(ARGS)

# Clean
clean:
	rm -f $(TARGET)
