#include <cs50.h>
#include <stdio.h>

// American Express uses 15-digit - start with 34 or 37
// MasterCard uses 16-digit -start with 51, 52, 53, 54, or 55
// Visa uses 13- and 16-digit - start with 4

int check_number(long card_number, int lenght);
int check_lenght(long card_number);
int check_type(long card_number);
int check_type_visa(long card_number);

int main(void)
{
    // Prompt to let the user insert the Credit Card number
    long n = get_long("Number: ");

    // Store the lenght of the Credit Card number
    int lenght = check_lenght(n);

    // Checking the Credit Card numner for the lenght, the first or the first 2 digits and the Luhn’s Algorithm
    if (check_lenght(n) == 15 && (check_type(n) == 34 || check_type(n) == 37) && check_number(n, lenght) == 0)
    {
        printf("AMEX\n");
    }
    else if (check_lenght(n) == 16 && (check_type(n) >= 51 && check_type(n) <= 55) && check_number(n, lenght) == 0)
    {
        printf("MASTERCARD\n");
    }

    else if ((check_lenght(n) == 16 || check_lenght(n) == 13) && (check_type_visa(n) == 4) && (check_number(n, lenght) == 0))
    {
        printf("VISA\n");
    }

    else
    {
        printf("INVALID\n");
    }

}


// FUNCTION to get the lenght of the credit card number
int check_lenght(long card_number)
{
    int count = 0;
    do
    {
        card_number /= 10;
        ++count;
    }
    while (card_number != 0);
    return count;
}

// FUNCTION to get the first 2 digits of a credit card number
int check_type(long card_number)
{
    while (card_number >= 100)
    {
        card_number = card_number / 10;
    }
    return card_number;
}

// FUNCTION to get the first digit of a credit card number
int check_type_visa(long card_number)
{
    while (card_number >= 10)
    {
        card_number = card_number / 10;
    }
    return card_number;
}

// FUNCTION to check the Credit Card number against the Luhn’s Algorithm
int check_number(long card_number, int lenght)
{
    // Create an array from the Credit Card number and lenght, takes the digits from right to left
    int array[lenght];

    for (int i = 0; i <= lenght - 1; i++)
    {
        array[i] = card_number % 10;

        card_number /= 10;
    }

    int sum_odds = 0;

    // Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together
    for (int k = 1; k <= lenght - 1; k += 2)
    {
        // Check if arra[k] times 2 is a 2 digits number
        if (array[k] * 2 < 9)
        {
            // If is 1 digit sum the number times 2
            sum_odds += array[k] * 2;
        }

        else
        {
            // If is 2 digits add the sum of the digits (12 = 1+2)
            sum_odds += ((array[k] * 2) / 10) + ((array[k] * 2) % 10);
        }

    }
    // Add the sum to the sum of the digits that weren’t multiplied by 2
    for (int w = 0; w <= lenght - 1; w += 2)
    {
        sum_odds += array[w];
    }

    // If the total modulo 10 is congruent to 0, the number is valid!
    if (sum_odds % 10 == 0)
    {
        return 0;
    }

    else
    {
        return 1;
    }
}
