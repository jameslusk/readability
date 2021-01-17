//James Lusk - cs50  12/2020 - problem set 2/readability

//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//Declaring functions
int get_index(string count);


//Main function
int main(void)
{
    //Prompt user to enter a string of text to be stored
    string text = get_string("Enter Text: ");
    
    //Apply index function
    int index = get_index(text);
    
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else 
    {
        printf("Grade %i\n", index);
    }
    
    return 0;

}

int get_index(string count)
{
    //declaring variables
    int letter = 0, word = 0, sentence = 0;
   
    //for-loop to get a letter, word, and sentence count
    for (int i = 0; i < strlen(count); i++)
    {
        char ch = count[i];
        
        //letter counter
        if (isalpha(ch))
        {
            letter++;
        }
        //word counter
        if (isspace(ch))
        {
            word++;
        }
        //sentence counter
        if (ch == '.' || ch == '!' || ch == '?')
        {
            sentence++;
        }
    }
    //adding words to account for words before and +after a space
    word++;
    
    //finding the average of letters per 100 words
    float L = (letter * 100.0f) / word;
    //finding the average of sentences per 100 words
    float S = (sentence * 100.0f) / word;
    //calculating the Coleman-Liau index
    return round(0.0588 * L - 0.296 * S - 15.8);
}