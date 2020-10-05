BIN=prgm.exe
CXXFLAGS=-o0 -W -Wall -g

OBJS=main.o shape.o circle.o rectangle.o compound_shape.o
DEPS=$(OBJS:.o=.d)

$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

run: $(BIN)
	./$(BIN)

r: clean run

clean:
	rm -rf $(OBJS) $(DEPS) $(BIN)