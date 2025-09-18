#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int i = get_int("Type a number\n");
    while (i > 0)
    {
        printf("Meow\n");
        i--;
    }
}
