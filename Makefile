# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -O2 -I./include

# Directories
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build

# Source files
SOURCES = $(SRC_DIR)/main.c \
          $(SRC_DIR)/utils.c \
          $(SRC_DIR)/bubble_sort.c \
          $(SRC_DIR)/gnome_sort.c \
          $(SRC_DIR)/radix_sort.c \
          $(SRC_DIR)/quick_sort.c \
          $(SRC_DIR)/heap_sort.c \
          $(SRC_DIR)/bucket_sort.c

# Target executable
TARGET = sort_test
TARGET_INTERACTIVE = sort_interactive

# Default target
all: $(TARGET) $(TARGET_INTERACTIVE)

# Link all object files (original version)
$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $^

# Link interactive version (professor's requirements)
$(TARGET_INTERACTIVE): $(SRC_DIR)/main_interactive.c \
                        $(SRC_DIR)/utils.c \
                        $(SRC_DIR)/bubble_sort.c \
                        $(SRC_DIR)/gnome_sort.c \
                        $(SRC_DIR)/radix_sort.c \
                        $(SRC_DIR)/quick_sort.c \
                        $(SRC_DIR)/heap_sort.c \
                        $(SRC_DIR)/bucket_sort.c
	$(CC) $(CFLAGS) -o $@ $^

# Clean build files
clean:
	rm -f $(TARGET) $(TARGET_INTERACTIVE)

# Run tests
test: $(TARGET)
	./$(TARGET) 1000

# Run interactive menu demo
interactive: $(TARGET_INTERACTIVE)
	./$(TARGET_INTERACTIVE)

# Run benchmark
benchmark: $(TARGET)
	@echo "n,bubble,bubble_opt,gnome,radix,quick,heap,bucket" > output/benchmark.csv
	@for size in 100 500 1000 2000 3000 4000 5000 7500 10000; do \
		./$(TARGET) $$size benchmark >> output/benchmark.csv; \
	done
	@echo "Benchmark data saved to output/benchmark.csv"

.PHONY: all clean test benchmark interactive

