# TH 2021

# TODO(TH): Explain static/dynamic libraries, linking etc as if to a beginner

CXX = g++

SRC = ./src
INCLUDE = ./include

CXXFLAGS = -g -Wall -std=c++2a -I$(INCLUDE)

OBJ = objs/libutils.o
TARGET = lib/libutils.a

all: $(TARGET)

# archive our library
$(TARGET): $(OBJ)
	ar -r $(TARGET) $(OBJ)

# $< is the first dependency, $@ is the target
# see https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html#Automatic-Variables
$(OBJ): $(SRC)/utils.cpp
		$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJ)
