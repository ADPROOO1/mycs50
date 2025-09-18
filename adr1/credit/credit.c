#include <cs50.h>
#include <stdio.h>

int get_digits(long cc_number);
int get_firstdigit(long cc_number);
// int get_seconddigit(long cc_numnber);
int get_sumotherproduct(long cc_number);
int get_sumproduct(long cc_number);
int get_secdigit(long cc_number);

int main(void)
{
    // Prompt the user to input CC number.
    long cc_number;
    do
    {
        cc_number = get_long("Credit Card Number: ");
    }
    while (cc_number < 0);
    // while (cc_number > 9999999999999999 || cc_number < 1000000000000);

    // Get first digit of CC number.
    int digits = get_digits(cc_number);
    int firstdigit = get_firstdigit(cc_number);
    int sumotherproduct = get_sumotherproduct(cc_number);
    int secdigit = get_secdigit(cc_number);

    // printf("Second Digit: %i\n", secdigit);
    // printf("SumOtherProduct: %i\n", sumotherproduct);

    int sumproduct = get_sumproduct(cc_number);
    // printf("SumProduct: %i\n", sumproduct);

    int checksum = sumotherproduct + sumproduct;
    // printf("CheckSum1: %i\n", checksum);

    checksum = checksum % 10;

    // printf("checksum: %i\n", checksum);

    if ((digits == 16 || digits == 13) && firstdigit == 4 && checksum == 0)
    {
        printf("VISA\n");
    }
    else if (digits == 15 && firstdigit == 3 && (secdigit == 4 || secdigit == 7) && checksum == 0)
    {
        printf("AMEX\n");
    }
    else if (digits == 16 && firstdigit == 5 &&
             (secdigit == 1 || secdigit == 2 || secdigit == 3 || secdigit == 4 || secdigit == 5) &&
             checksum == 0)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
    // printf("CC Number: %ld\n", cc_number);
}

// CCTypeCheck - Checks the type of CC (AMEX, VISA or MASTERCARD).
// VisaTypeCheck - Check if CC number starts with 4.
// Get first digit of CC number.

int get_digits(long cc_number)
{
    int digits = 1;
    for (; cc_number > 10; cc_number /= 10)
    {
        digits++;
    }
    return digits;
}

int get_firstdigit(long cc_number)
{
    int firstdigit = 0;
    while (cc_number > 9)
    {
        firstdigit = cc_number - cc_number % 10;
        cc_number /= 10;
    }
    firstdigit /= 10;

    return firstdigit;
}

int get_sumotherproduct(long cc_number)
{
    int sumotherproduct = 0;

    while (cc_number > 9)
    {                                    // CCNumber = 4,222,222,222,222
        int other_product = 0;           // Product = 0
        other_product = cc_number % 100; // Product = 22
        other_product /= 10;             // Product = 2
        cc_number /= 100;                // CCNumber = 4,222,222,222,2
        other_product *= 2;              // Product = 4
        if (other_product > 9)
        {
            int i = other_product % 10; // 16
            int p = other_product / 10;
            other_product = i + p;
        }
        for (int i = other_product; i > 0; i--)
        {
            sumotherproduct++;
        }
    }
    return sumotherproduct;
}

int get_sumproduct(long cc_number)
{
    int sumproduct = 0;
    sumproduct = cc_number % 10; // sumproduct = 2
    cc_number = cc_number / 10;  // ccnumber = 4,222,222,222,22_

    while (cc_number > 9)
    {
        int product = 0;           // Product is 0
        product = cc_number % 100; // Product is 22
        product /= 10;             // Product is 2
        cc_number /= 100;          // CCNumber is 4,222,222,222,_2_
        for (int i = product; i > 0; i--)
        {
            sumproduct++;
        }
    }
    return sumproduct;
}

int get_secdigit(long cc_number)
{
    int secdigit = 0;
    while (cc_number > 99)
    {
        secdigit = cc_number - cc_number % 10;
        cc_number /= 10;
    }
    secdigit /= 10;
    secdigit %= 10;
    return secdigit;
}
