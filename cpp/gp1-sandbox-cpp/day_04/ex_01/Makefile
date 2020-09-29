BIN=prgm
CXXFLAGS=-o0 -W -Wall -g

OBJS=main.o student.o classroom.o
DEPS=$(OBJS:.o=.d)

$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

run: $(BIN)
	./$(BIN)

r: clean run

clean:
	rm -rf $(OBJS) $(DEPS) $(BIN)