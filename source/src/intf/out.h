 #pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

void print_char(char character);
void print_string(char* string);
void print_clear();
void print_push();
void print_color(uint8_t fg, uint8_t bg);
bool print_EOL();
