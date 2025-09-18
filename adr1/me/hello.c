#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string firstname = get_string("First Name: ");
    string lastname = get_string("Last Name: ");
    printf("Hello, %s %s!\n", firstname, lastname);
}
