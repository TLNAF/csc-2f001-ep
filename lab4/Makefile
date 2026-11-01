.SUFFIXES:         # remove all the implicit rules (avoid conflicts with our own rules)
.SECONDARY:        # all files are intermediate (keep them, otherwise they are removed)
.PHONY: all clean  # these targets are not files (even if a file named "all" or "clean" exists, the rule is applied)

LDFLAGS=
LIBS=
CXXFLAGS=-Wall -Werror -g
BIN=bilbao

all: $(BIN)

bilbao: main.o
	g++ $(LDFLAGS) -o $@ $^ $(LIBS)

%.o: %.cpp 
	g++ $(CXXFLAGS) -o $@ -c $<

clean:
	rm -f $(BIN) *.o *~ 