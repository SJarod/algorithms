
CC?=gcc
TARGET?=$(shell $(CC) -dumpmachine)

CFLAGS=-Wall -g -O0 -fPIC -I../externals/include
CPPFLAGS=-MMD

ifeq ($(OS),Windows_NT)
LDFLAGS=-L../externals/$(TARGET)/libs
LDLIBS=-lgpdll -lglfw3dll -lgdi32 -lglu32
else
LD_LIBRARY_PATH=../externals/$(TARGET)/libs
LDFLAGS+=-L../externals/$(TARGET)/bin -Wl,-rpath,$(LD_LIBRARY_PATH)
LDLIBS=-lgp -lglfw
endif

OBJS=src/main.o src/draw.o src/draw_functions.o
DEPS=$(OBJS:.o=.d)

.PHONY: all clean run

all: draw

-include $(DEPS)

draw: $(OBJS) src/draw_line_bresenham.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@

run: draw
	PATH=$$PATH:../externals/$(TARGET)/bin ./$<

clean:
	rm -f $(OBJS) $(DEPS) draw
