#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("What's X? \n");
    int y = get_int("What's y? \n");

    if (x < y)
    {
        printf("%i is less than %i\n", x, y);
    }
    else if (x > y)
    {
        printf("%i is greater than %i\n", x, y);
    }
    else
    {
        printf("%i is equal to %i\n", x, y);
    }
}
