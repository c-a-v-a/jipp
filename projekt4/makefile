CC = gcc
CFLAGS = -s
DBG_FLAGS = -g -fsanitize=leak

GLOBAL_FILES = src/student.c src/menu.c src/strlib.c

STACK_FILES = $(GLOBAL_FILES) src/stack/main.c src/stack/stack.c
STACK_BIN = bin/stack

QUEUE_FILES = $(GLOBAL_FILES) src/queue/main.c src/queue/queue.c
QUEUE_BIN = bin/queue

ASTACK_FILES = $(GLOBAL_FILES) src/astack/main.c src/astack/stack.c
ASTACK_BIN = bin/astack

AQUEUE_FILES = $(GLOBAL_FILES) src/aqueue/main.c src/aqueue/queue.c
AQUEUE_BIN = bin/aqueue

dbg_stack: $(STACK_FILES)
	$(CC) -o $(STACK_BIN) $(STACK_FILES) $(DBG_FLAGS)

stack: $(STACK_FILES)
	$(CC) -o $(STACK_BIN) $(STACK_FILES) $(CFLAGS)

dbg_queue: $(QUEUE_FILES)
	$(CC) -o $(QUEUE_BIN) $(QUEUE_FILES) $(DBG_FLAGS)

queue: $(QUEUE_FILES)
	$(CC) -o $(QUEUE_BIN) $(QUEUE_FILES) $(FLAGS)

dbg_astack: $(ASTACK_FILES)
	$(CC) -o $(ASTACK_BIN) $(ASTACK_FILES) $(DBG_FLAGS)

astack: $(ASTACK_FILES)
	$(CC) -o $(ASTACK_BIN) $(ASTACK_FILES) $(CFLAGS)

dbg_aqueue: $(AQUEUE_FILES)
	$(CC) -o $(AQUEUE_BIN) $(AQUEUE_FILES) $(DBG_FLAGS)

aqueue: $(AQUEUE_FILES)
	$(CC) -o $(AQUEUE_BIN) $(AQUEUE_FILES) $(FLAGS)

