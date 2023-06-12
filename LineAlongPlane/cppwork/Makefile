CXX = clang

CXXFLAGS = -Wall -O

OBJECTS = chargeDistribution.o

LIBS = -lgsl -lgslcblas -lm

gslmake: $(OBJECTS)
	$(CXX) -o chargeDistribution $(CXXFLAGS) $(OBJECTS) $(LIBS)

evolutionProgression.o: chargeDistribution.c

clean:
	-rm -f *.o *~ a.out
