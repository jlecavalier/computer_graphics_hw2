# Example 10
EXE=hw2

# Main target
all: $(EXE)

#  MinGW
ifeq "$(OS)" "Windows_NT"
CFLG=-O3 -Wall
LIBS=-lglut32cu -lglu32 -lopengl32
CLEAN=del *.exe *.o *.a
else
#  OSX
ifeq "$(shell uname)" "Darwin"
CFLG=-O3 -Wall -Wno-deprecated-declarations
LIBS=-framework GLUT -framework OpenGL
#  Linux/Unix/Solaris
else
CFLG=-O3 -Wall
LIBS=-lglut -lGLU -lGL -lm
endif
#  OSX/Linux/Unix/Solaris
CLEAN=rm -f $(EXE) src/*.o src/*.a src/auxiliary/*.o
endif

# Dependencies
src/hw2.o: src/hw2.c src/hw2_defs.h
src/auxiliary/print.o: src/auxiliary/print.c src/hw2_defs.h

# Create archive
src/hw2_defs.a:src/auxiliary/print.o
	ar -rcs $@ $^

# Compile rules
src/%.c.o:
	gcc -c $(CFLG) $<
src/%.cpp.o:
	g++ -c $(CFLG) $<
src/auxiliary/%.c.o:
	gcc -c $(CFLG) $<
src/%.cpp.o:
	g++ -c $(CFLG) $<

# Link
hw2:src/hw2.o src/hw2_defs.a
	gcc -O3 -o $@ $^ $(LIBS)

# Clean
clean:
	$(CLEAN)	