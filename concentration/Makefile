OBJS = IntGame StringGame AbilityGame

CXXFLAGS = -g -O2 -Wall -Wextra -Wpedantic -Werror --std=c++23 -Wnon-virtual-dtor -Wold-style-cast -Wunused-parameter -Wuninitialized  -Winit-self  -Wshadow  -Wparentheses -Wdangling-else 

all: ${OBJS}

AbilityT.o: AbilityT.h
CardTest: CardT.h
Array2TTest: Array2T.h CardT.h ArrayT.h
ConcentrationT.h: Array2T.h CardT.h ArrayT.h PlayerT.h AbilityT.o
IntGame: ConcentrationT.h
StringGame: ConcentrationT.h
AbilityGame: ConcentrationT.h AbilityT.o

clean:
	rm -f ${OBJS} *.o
