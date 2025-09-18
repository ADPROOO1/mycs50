#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int change = 0;
    int change_owed = 0;
    do
    {
        change = get_int("Change owed: ");
    }
    while (change < 0);
    // Checks if change is > 25, if true then deduct 25 until false
    while (change >= 25)
    {
        change -= 25;
        change_owed++;
    }
    while (change >= 10)
    {
        change -= 10;
        change_owed++;
    }
    while (change >= 5)
    {
        change -= 5;
        change_owed++;
    }
    while (change >= 1)
    {
        change -= 1;
        change_owed++;
    }
    printf("%i\n", change_owed);
}
