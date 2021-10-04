#include <cs50.h>
#include <stdio.h>

int main(void)
{

    // Get an integer from the user
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // number of rows to print
    for (int i = 1; i <= height; i++)
    {
        // Print spaces
        for (int x = 0; x < (height - i); x++)
        {
            printf(" ");
        }

        //Print #
        for (int y = 0; y < i ; y++)
        {
            printf("#");
        }

        printf("  ");

        //Print #
        for (int y = 0; y < i ; y++)
        {
            printf("#");
        }

        printf("\n");

    }

}
