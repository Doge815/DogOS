 #pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef enum {
    BLACK = 0,
	BLUE = 1,
	GREEN = 2,
	CYAN = 3,
	RED = 4,
	MAGENTA = 5,
	BROWN = 6,
	LIGHT_GRAY = 7,
	DARK_GRAY = 8,
	LIGHT_BLUE = 9,
	LIGHT_GREEN = 10,
	LIGHT_CYAN = 11,
	LIGHT_RED = 12,
	PINK = 13,
	YELLOW = 14,
	WHITE = 15,
} Color;

void print_char(char character);
void print_string(char* string);
void print_clear(bool resetPos);
void print_push();
void print_newLine();
void print_setColor(Color fg, Color bg);
bool print_EOL();
