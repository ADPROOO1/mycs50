#include <cs50.h>
#include <stdio.h>

void print_space(int a);
void print_hash(int b);

int main(void)
{
    int height;
    // PROMPT USER FOR PYRAMID HEIGHT
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    // PRINT ROWS OF BRICKS
    for (int row = 0; row < height; row++)
    {
        // PRINT LEFT SPACES
        print_space(height - row);
        print_hash(row);
        printf("\n");
    }
}
void print_space(int a)
{
    while (a > 1)
    {
        printf(" ");
        a--;
    }
}
void print_hash(int b)
{
    for (int i = 0; i <= b; i++)
    {
        printf("#");
    }
    printf("  ");
    for (int j = 0; j <= b; j++)
    {
        printf("#");
    }
}
