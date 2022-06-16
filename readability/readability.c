#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int calculate_score(float L, float S);

int main(void)
{
    string text = get_string("Text: ");

    // Count the number of words, letters and sentences

    int number_of_words = count_words(text);

    int number_of_letters = count_letters(text);

    int number_of_sentences = count_sentences(text);

    // Calculate reading level according to the Coleman-Liau index
    // ? L = letters / words * 100 and S = sentences / words * 100

    float L = (float)number_of_letters / (float)number_of_words * 100;
    float S = (float)number_of_sentences / (float)number_of_words * 100;

    int score = calculate_score(L, S);

    if (score < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (score > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", score);
    }
}

int count_letters(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

int count_words(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]))
        {
            count++;
        }
    }
    // Returns count + 1 since there is no space following the last word
    return ++count;
}

int count_sentences(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Seperate sentences
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            count++;
        }
    }
    return count;
}

int calculate_score(float L, float S)
{
    int index = round((0.0588 * L) - (0.296 * S) - 15.8);
    return index;
}