OUTPUT = test

CXX=g++
CXXFLAGS+=-Wall -O0 $(GXX_FLAGS) -std=c++11
CXXFLAGS+=-g
#Dependency for the ouotpu file
#DEP_FLAGS=-MMD
#DEP_FLAGS+=-MP

#SRC=main.cpp fun.cpp
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)

#Add dependency generation to the compiler options 
CXXFLAGS+=$(DEP_FLAGS)

all: $(OUTPUT)

$(OUTPUT): $(OBJ)
	$(CXX) $(LFLAGS) $(OBJ) -o $@

.PHONY: clean run

clean:
	@rm -f program $(OBJ) $(DEP)

-include $(DEP)
