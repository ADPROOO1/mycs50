#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int i = 1;
    do
    {
        int action;
        do
        {
            action = get_int("0 to Create Contact\n1 to Search Contact\nInput Action: ");
        }
        while (action < 0 || action > 1);

        string firstcontact_name;
        int firstcontact_age = 0;
        long firstcontact_number = 0;

        if (action == 0)
        {
            firstcontact_name = get_string("First Name: ");

            do
            {
                firstcontact_age = get_int("Age: ");
            }
            while (firstcontact_age < 0);

            do
            {
                firstcontact_number = get_long("Number: ");
            }
            while (firstcontact_number < 0);

            if (int p = 0)
            i = get_int("Contact Saved\n 0 to Create Contact\n1 to Find Contact\nInput Action: ");

        }
    }
    while (i > 0);
}

    string firstcontact_name = NULL;
    int firstcontact_age = 0;
    long firstcontact_number = 0;

    if (action == 0 && firstcontact_name == NULL)
    {
        printf("firstcontact\n");
        do
        {
            firstcontact_name = get_string("Full Name: ");
        }
        while (firstcontact_name == NULL);

        do
        {
            firstcontact_age = get_int("Age: ");
        }
        while (firstcontact_age < 0 || firstcontact_age > 99);

        do
        {
            firstcontact_number = get_int("Number: ");
        }
        while (firstcontact_number < 0);
    }
}
