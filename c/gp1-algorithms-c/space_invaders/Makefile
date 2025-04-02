
PLATFORM?=linux_x64
LD_LIBRARY_PATH=../externals/bin/linux_x64

CC?=gcc
CFLAGS=-g -O0 -fPIC -I../externals/include
CPPFLAGS=-MMD

ifeq ($(PLATFORM),linux_x64)
LDFLAGS+=-L../externals/bin/$(PLATFORM) -Wl,-rpath,$(LD_LIBRARY_PATH)
LDLIBS=-lgp -lglfw
else
LDFLAGS=-L../externals/libs/windows_x64
LDLIBS=-lgpdll -lglfw3dll -lgdi32 -lglu32
endif

OBJS=src/main.o src/game.o src/game_functions.o
DEPS=$(OBJS:.o=.d)

.PHONY: all clean

all: invaders

-include $(DEPS)

invaders: $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@

clean:
	rm -f $(OBJS) $(DEPS) invaders

