#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<math.h>

int main(void) {
    //getting text
    string text = get_string("Text: \n");
    //preparing variables
    int length = strlen(text);
    int letters = 0;
    int words = 1;
    int sentences = 0;
    //Running through characters
    for(int i = 0; i < length; i++) {
        //counting number of letters
        if(text[i] > 64 & text[i] < 91) {
            letters = letters + 1;
        }
        if(text[i] > 96 & text[i] < 123) {
            letters = letters + 1;
        }
        //counting number of words
        if(text[i] == 32) {
            words = words + 1;
        }
        //counting number of sentences
        if(text[i] == 33 | text[i] == 46 | text[i] == 63) {
            sentences = sentences + 1;
        }
    }
    if(sentences == 0) {
        sentences = 1;
    }
    //converting int valeus into float values
    float fletters = (float) letters;
    float fwords = (float) words;
    float fsentences = (float) sentences;
    //Indices L e S
    double ele = 100 * letters / words;
    double esse = 100 * sentences / words;
    //calculate index
    double index = 0.0588 * ele - 0.296 * esse - 15.8;

    //output:
    if(index < 1) {
        printf("Below grade 1.\n");
    }
    if(index >= 1 & index <= 16) {
        printf("Grade %i\n", (int) round(index));
    }
    if(index > 16) {
        printf("Grade 16+\n");
    }
}