# TH 2021

CXX = g++

UTILS_LIB = ../utils/lib
INCLUDE = ../utils

CXXFLAGS = -g -Wall -std=c++2a -I$(INCLUDE)
LDFLAGS = -L$(UTILS_LIB) -static -lutils

TARGET = solve

all: $(TARGET)

$(TARGET): $(TARGET).cpp
		$(CXX) $(TARGET).cpp $(LDFLAGS) $(CXXFLAGS) -o $(TARGET)

clean:
		$(RM) $(TARGET)
