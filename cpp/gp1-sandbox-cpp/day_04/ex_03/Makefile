BIN=prgm
CXXFLAGS=-o0 -W -Wall -g

OBJS=main.o part.o engine.o diesel.o fuel.o wheel.o small_wheel.o big_wheel.o
DEPS=$(OBJS:.o=.d)

$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

run: $(BIN)
	./$(BIN)

r: clean run

clean:
	rm -rf $(OBJS) $(DEPS) $(BIN)