#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int handle_errors(int argc, string key);
void substitute(string key, string plaintext);

int main(int argc, string argv[])
{
    string key = argv[1];
    int exit_status = handle_errors(argc, key);

    if (exit_status == 1)
    {
        return exit_status;
    }
    else
    {
        string plaintext = get_string("plaintext: ");
        substitute(key, plaintext);
    }
}

int handle_errors(int argc, string key)
{
    // Handles error if the user does not provide a key or passes many keys
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Handles error if the user passes a key of invalid length
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0, n = strlen(key); i < n; i++)
    {
        // Handles error if the user passes a key with invalid characters
        if (!isalpha(key[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }

        for (int j = i + 1; j < n + 1; j++)
        {

            // Handles error if the user passes a key with repeated characters
            if (key[i] == key[j])
            {

                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }
}

void substitute(string key, string plaintext)
{
    int length_of_plaintext = strlen(plaintext);
    char ciphertext[length_of_plaintext];

    for (int i = 0, n = length_of_plaintext; i < n; i++)
    {
        // Strictly modifies the alphabetic part of the string
        if (isalpha(plaintext[i]))
        {
            int index = toupper(plaintext[i]) - 65;

            // Substitutes the characters irrespective of the case
            if (islower(plaintext[i]))
            {
                ciphertext[i] = tolower(key[index]);
            }
            else
            {
                ciphertext[i] = toupper(key[index]);
            }
        }
        // The non-alphabetic part of the string remains the same
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }

    printf("ciphertext: %s\n", ciphertext);
}