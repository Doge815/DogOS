#include "out.h"

extern const char Doge[];

void main()
{
    print_setColor(WHITE, BLUE);
    print_clear(true);
    print_string("remove me!\n");
    print_string(Doge);
    print_newLine();
    print_char('D');
    print_string("ogOS");
    print_newLine();
    print_char('\n');
    print_string("WOW");
    print_push();
}