CC=gcc
FLAGS=-Wall -Werror -Wvla -Wvla -Wuninitialized -Wextra -g -fsanitize=address,leak
OBJS=main.o nodes.o
TARGET=mtll

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(FLAGS) $^ -o $@

%.o: %.c
	$(CC) -c $(FLAGS) $< -o $@

build: all

clean:
	rm -f $(OBJS)
	rm -f $(TARGET)

