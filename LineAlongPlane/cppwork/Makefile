CXX = clang

CXXFLAGS = -Wall -g

OBJECTS = evolutionProgression.o

LIBS = -lgsl -lgslcblas -lm

gslmake: $(OBJECTS)
	$(CXX) -o evolutionProgression $(CXXFLAGS) $(OBJECTS) $(LIBS)

evolutionProgression.o: evolutionProgression.c

clean:
	-rm -f *.o *~ a.out
