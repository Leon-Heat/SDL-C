PROG = start
CC = gcc

OUT = bin
vpath %.c src
vpath %.h src
vpath %.o bin
CFLAGS = -lSDL2 -lSDL2_image -lm
DEPS = defs.h structs.h


_OBJS += init.o draw.o input.o util.o entity.o
_OBJS += main.o

OBJS = $(patsubst %,$(OUT)/%,$(_OBJS))

all: $(PROG)

$(OUT)/%.o: %.c %.h $(DEPS)
	@mkdir -p $(OUT)
	$(CC) $(CFLAGS) -c -o $@ $<

$(PROG): $(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAGS)

clean:
	$(RM) -rf $(OUT) $(PROG)
