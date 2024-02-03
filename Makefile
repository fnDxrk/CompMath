CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

TARGET = my_program

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
