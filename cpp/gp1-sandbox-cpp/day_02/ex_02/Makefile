BIN=prgm
CXXFLAGS=-o0 -W -Wall -g

OBJS=main.o ex_02.o
DEPS=$(OBJS:.o=.d)

$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

run: $(BIN)
	./$(BIN)

clean:
	rm -rf $(OBJS) $(DEPS) $(BIN)