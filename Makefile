all: ezgleng


WARNINGS = -Wall
DEBUG = -ggdb -fno-omit-frame-pointer
OPTIMIZE = -O2
OPENGL = -lGL -lglfw -lm


ezgleng: Makefile main.cpp
	$(CXX) -o $@ $(OPENGL) $(WARNINGS) $(DEBUG) $(OPTIMIZE) main.cpp

clean:
	rm -f ezgleng

# Builder will call this to install the application before running.
install:
	echo "Installing is not supported"

# Builder uses this target to run your application.
run:
	./ezgleng

