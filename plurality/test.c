#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "cs50.h"

int main(void)
{
    int candidate_count = 3;
    string candidates[] = {"Alice", "Bob", "Charlie"};
    // TODO
    int match = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        string name = get_string("Vote: ");
        if (name == candidates[i])
        {
            match++;
            printf("Vote counted for %s\n", candidates[i]);
        }
    }
    printf("Total votes counted: %d\n", match);
}
