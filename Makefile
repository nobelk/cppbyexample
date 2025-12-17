# Compiler settings
CXX = clang++
CXXFLAGS = -Wall -Wextra -pedantic
LDFLAGS =

# Directories
BUILD_DIR = build
BIN_DIR = bin

# Main executable
TARGET = $(BIN_DIR)/cppbyexample

# Default target
all: $(BIN_DIR) $(BUILD_DIR) $(TARGET)

# Create directories if they don't exist
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Build main executable from main.cpp (which includes src/containers.cpp)
$(TARGET): src/main.cpp
	$(CXX) $(CXXFLAGS) src/main.cpp -o $(TARGET)

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# Rebuild everything
rebuild: clean all

# Run the executable
run: all
	$(TARGET)

.PHONY: all clean rebuild run
