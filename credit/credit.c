#include <cs50.h>
#include <stdio.h>
#include <math.h>

int checksum(long credit_card);
int get_length(long credit_card);
void print_card_type(int length, long credit_card);

int main(void)
{
    long credit_card = get_long("Credit card number: ");
    int length = get_length(credit_card);

    if (length < 13 || length > 16)
    {
        printf("INVALID\n");
    }
    else
    {
        int sum = checksum(credit_card);

        if (sum % 10 == 0)
        {
            print_card_type(length, credit_card);
        }
        else
        {
            printf("INVALID\n");
        }
    }
}

int get_length(long credit_card)
{
    int length = 0;
    long credit_card_copy = credit_card;

    while (credit_card_copy > 0)
    {
        credit_card_copy /= 10;
        length++;
    }

    return length;
}

void print_card_type(int length, long credit_card)
{
    long n_amex_mastercard = pow(10, length - 2);
    long n_visa = pow(10, length - 1);

    if (length == 15 && (credit_card / n_amex_mastercard == 34 || credit_card / n_amex_mastercard == 37))
    {
        printf("AMEX\n");
    }
    else if (length == 16 && (credit_card / n_amex_mastercard == 51 || credit_card / n_amex_mastercard == 52
|| credit_card / n_amex_mastercard == 53 || credit_card / n_amex_mastercard == 54 || credit_card / n_amex_mastercard == 55))
    {
        printf("MASTERCARD\n");
    }
    else if (length == 13 && (credit_card / n_visa == 4) || length == 16 && (credit_card / n_visa == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

int checksum(long credit_card)
{
    long credit_card_copy = credit_card;
    int sum = 0;

    // Removes the last digit
    credit_card_copy /= 10;

    while (credit_card_copy > 0)
    {
        // Multiplies the digit by 2
        int last_number = credit_card_copy % 10 * 2;

        // Skips one digit
        credit_card_copy /= 100;

        // Breaks down the integer and adds its values if the value is greater than 9
        if (last_number > 9)
        {

            int first_number = last_number % 10;
            int second_number = last_number / 10;

            sum += first_number + second_number;
        }
        else
        {
            sum += last_number;
        }
    }

    credit_card_copy = credit_card;

    // Adds the values of every other digit to the sum
    while (credit_card_copy > 0)
    {
        int last_number = credit_card_copy % 10;
        credit_card_copy /= 100;
        sum += last_number;
    }

    return sum;
}
