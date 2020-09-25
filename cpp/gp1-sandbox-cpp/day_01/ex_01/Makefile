BIN=exe
CXXFLAGS=-O0 -W -Wall -g

OBJS=main.o
DEPS=$(OBJS:.o=.d)

$(BIN): $(OBJS)
	  $(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -rf $(OBJS) $(BIN)