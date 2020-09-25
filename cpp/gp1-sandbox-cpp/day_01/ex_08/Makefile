BIN=prgm
CXXFLAGS=-O0 -W -Wall -g

OBJS=main.o ex_08.o
DEPS=$(OBJS:.o=.d)

$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

run: $(BIN)
	./$(BIN)

clean:
	rm -rf $(OBJS) $(DEPS) $(BIN)