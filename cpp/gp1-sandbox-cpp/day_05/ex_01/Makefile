BIN=prgm.exe
CXXFLAGS=-o0 -W -Wall -g

OBJS=main.o animal.o sloth.o panda.o sloda.o
DEPS=$(OBJS:.o=.d)

$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

run: $(BIN)
	./$(BIN)

r: clean run

clean:
	rm -rf $(OBJS) $(DEPS) $(BIN)