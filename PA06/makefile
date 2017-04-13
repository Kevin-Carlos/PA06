# target executable name
TARGET = PA06

# Compiler
CC=g++

# Compiler flags
CXXFLAGS = -g -Wall -std=c++11

# Source files
SOURCES = BinarySearchTree.cpp

# header file dependencies
HEADERS = BinarySearchTree.h

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# default target 
all:		$(TARGET)

# link everything together
$(TARGET):	$(OBJECTS)
				$(CC) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

$(OBJECTS):	$(SOURCES) $(HEADERS)
				$(CC) $(CXXFLAGS) -c $(SOURCES)

# clean target
clean:
		rm $(TARGET) $(OBJECTS)

