#include <cs50.h>
#include <stdio.h>

void print_space(void);
void print_hash(void);

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // PRINT ROWS
    int space = height;
    int hash = 1;

    for (int i = 0; i < height; i++)
    {
        // PRINT SPACES
        for (int j = 1; j < space; j++)
        {
            printf(" ");
        }

        // PRINT HASHES
        for (int k = 0; k < hash; k++)
        {
            printf("#");
        }

        hash++;
        space--;
        printf("\n");
    }
}
