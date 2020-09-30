BIN=prgm
CXXFLAGS=-o0 -W -Wall -g

OBJS=main.o entity.o non_playable_character.o object.o playable_character.o
DEPS=$(OBJS:.o=.d)

$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

run: $(BIN)
	./$(BIN)

r: clean run

clean:
	rm -rf $(OBJS) $(DEPS) $(BIN)