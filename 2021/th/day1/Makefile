# TH 2021
# This is a makefile.
# Make is a tool to automate building stuff.
# Our makefile will tell Make what to do
# Even with small 1-file projects I find it's quicker to write a makefile once
# rather than use the compiler directly.

# See https://www.gnu.org/software/make/manual/make.html

# compiler. I'm using g++ to compile my c++ code.
CXX = g++

# our utilities library directory
# it definitely wasn't necessary to create this library, but learning
UTILS_LIB = ../utils/lib

# includes
INCLUDE = ../utils

# compiler flags:
# See https://caiorss.github.io/C-Cpp-Notes/compiler-flags-options.html
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
#  -std   - this flag sets the c++ standard, we're using c++20, pog!
#  -I	  - this flag allows us to specify a directory to include files from
CXXFLAGS = -g -Wall -std=c++2a -I$(INCLUDE)

# linker flags:
#  -L     	- tells the linker where to look for libraries
#  -static  - link a static library
#  -lutils  - link a library named utils (the linker will look for libutils.a)
LDFLAGS = -L$(UTILS_LIB) -static -lutils

# The build target (our 1 cpp file)
TARGET = solve

# These are targets we call from the command line to get make to do stuff
# e.g. "make all", "make clean"
all: $(TARGET)

# gotcha: load libraries after target otherwise undefined references
$(TARGET): $(TARGET).cpp
		$(CXX) $(TARGET).cpp $(LDFLAGS) $(CXXFLAGS) -o $(TARGET)

clean:
		$(RM) $(TARGET)
