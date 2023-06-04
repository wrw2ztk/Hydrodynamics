CXX = clang

CXXFLAGS = -Wall -g

OBJECTS = practiceGSL.o

LIBS = -lgsl -lgslcblas -lm

gslmake: $(OBJECTS)
	$(CXX) -o practiceGSL $(CXXFLAGS) $(OBJECTS) $(LIBS)

practiceGSL.o: practiceGSL.c

clean:
	-rm -f *.o *~ a.out
