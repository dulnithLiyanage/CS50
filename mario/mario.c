#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    } 
    while (height <= 0 || height > 8);

    for (int i = 0; i < height; i++)
    {
        // Indents the pyramid
        for (int j = height - 1; j > i; j--)
        {
            printf(" ");
        }

        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }

        // Adds space between each pyramid
        for (int l = 0; l < 2; l++)
        {
            printf(" ");
        }

        for (int m = 0; m <= i; m++)
        {
            printf("#");
        }

        printf("\n");
    }
}
