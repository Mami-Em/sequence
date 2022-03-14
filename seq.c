#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    // get input
    int clue = get_int("How many numbers do you have? ");
    // create an array depending on how many numbers have the user inserted
    int tab[clue];
    for (int i = 0; i<clue; i++) {
        tab[i] = get_int("number n %i: ", i+1);
    } 
    // get an array of the value
    printf("The array we get is: [");
    for (int j = 0; j<clue; j++) {
        printf(" %i", tab[j]);
    }
    printf(" ]\n");
    // create a function that check the sequence
}