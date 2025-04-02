BIN=prgm
CXXFLAGS=-O0 -W -Wall -g

OBJS=ex_05.o main.o
DEPS=$(OBJS:.o=.d)

$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

run: $(BIN)
	./$(BIN)

clean:
	rm -rf $(OBJS) $(DEPS) $(BIN)