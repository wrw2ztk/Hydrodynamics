CXX = clang

CXXFLAGS = -Wall -g

OBJECTS = integrationPractice.o

LIBS = -lgsl -lgslcblas -lm

gslmake: $(OBJECTS)
	$(CXX) -o practiceGSL $(CXXFLAGS) $(OBJECTS) $(LIBS)

integrationPractice.o: integrationPractice.c

clean:
	-rm -f *.o *~ a.out
