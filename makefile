CC = gcc
CFLAGS = -Wall -I./include -g
LDFLAGS =
SRCS = src/main.c src/toss.c src/interface.c src/logic.c
OBJS = $(SRCS:.c=.o)
TARGET = game

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS) # <-- 3. Add $(LDFLAGS) here

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)