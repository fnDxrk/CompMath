CXX = g++
CXXFLAGS = -std=c++11 -Wall

DIR = Gauss
SRC_DIR = $(DIR)/src
BUILD_DIR = $(DIR)/build
INCLUDE_DIR = $(DIR)/include
BIN_DIR = $(DIR)/bin

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

TARGET = $(BIN_DIR)/my_program

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -I$(INCLUDE_DIR) -o $@

clean:
	rm -f $(OBJS) $(TARGET)
