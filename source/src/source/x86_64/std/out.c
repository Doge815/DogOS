#include "out.h"

struct Symbol
{
    char character;
    uint8_t color;
};

struct Symbol* buffer = (struct Symbol*) 0xb8000;
const static uint8_t Cols = 80;
const static uint8_t Rows = 25;
uint8_t pos_col = 0;
uint8_t pos_row = 0;
Color FG = WHITE;
Color BG = BLACK;

struct Symbol ToSymbol(char _character)
{
    return (struct Symbol) {character: _character, color: (FG + (BG << 4))};
}

bool isprint(char character)
{
    uint8_t val = (uint8_t) character;
    return (val > 32 && val < 127);
}

void print_char(char character)
{
    if(isprint(character))
    {
        if(print_EOL())
        {
            print_newLine();
        }

        buffer[pos_col + pos_row * Cols] = ToSymbol(character);
        pos_col++;
    }
    else
    {
        switch (character)
        {
        case '\n':
            print_newLine();
            break;
        //Todo: add \r, backslash...
        default:
            break;
        }
    }
}

void print_string(char* string)
{
    for (uint16_t i = 0; true; i++)
    {
        char character = (uint8_t) string[i];

        if (character == '\0')
        {
            return;
        }

        print_char(character);
    }
}

void clearRow(uint8_t row)
{
    for(int i = 0; i < Cols; i++)
    {
        buffer[row * Cols + i] = ToSymbol(' ');
    }
}
void print_clear(bool resetPos)
{
    for(int i = 0; i < Rows; i++)
    {
        clearRow(i);
    }
    if(resetPos)
    {
        pos_col = 0;
        pos_row = 0;
    }
}
void print_push()
{
    for (uint8_t i = 1; i < Rows; i++)
    {
        for (uint8_t u = 0; u < Cols; u++)
        {
            buffer[(i - 1) * Rows + u] = buffer[i * Rows + u];
        }
    }
    clearRow(Rows - 1);
    
}
void print_newLine()
{
    pos_col = 0;
    if(pos_row == Rows - 1)
    {
        print_push();
        return;
    }
    pos_row++;
}
void print_setColor(Color fg, Color bg)
{
    FG = fg;
    BG = bg;
}
bool print_EOL()
{
    return (pos_col >= Cols);
}
