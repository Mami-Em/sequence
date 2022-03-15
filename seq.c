#include <cs50.h>
#include <stdio.h>
#include <string.h>

int check(float val[], int c);

int main(void) {
    // get input
    int clue = get_int("How many numbers do you have? ");
    // reurn 1 if number to few
    if (clue < 3)
    {
        printf("The number inserted should be more or equal to three.\n");
        return 1;
    }
    float tab[clue];
    
    for (int i = 0; i<clue; i++) 
        // insert values in an array
        tab[i] = get_int("number n %i: ", i+1);
    // create a function that check the sequence
    check(tab, clue);
    // char next = get_char("Do you have more work for me?Y/N. ");
    // if (next == 'n' || next == 'N') {
    //     return 1;
    // }
    // printf("mbola mitohy\n");
    return 0;
}
// fib: -> x(n) = x(n-1) + x(n-2)
// geo: -> x(n) = x(1)r^(n-1)
// arithm: -> x(n) = x(1) + x(n-1)(r)

int check(float val[], int c) {
    double geom[c]; 
    int ed, arithm[c], fibo[c];
    int i = 1, j = 0;
    while(i<c && j<c-1) {
        arithm[j] = val[i] - val[j];
        geom[j] = val[i] / val[j];
        i++, j++;
    }
    // check if geom
    if(geom[0] == geom[1])
    // geom[1] == geom[2]
    // -> if geom -- next seq and proof
        printf("geometric sequence\n");
    // -> else check if arithm
    else {
        // -> if arithm -- next seq and proof
        if(arithm[0] == arithm[1])
            printf("arithmetic sequence\n");
        // -> else check if fibonacci 
        else {
            // -> if fibo -- next seq and proof
            if ((val[0]+val[1]) == val[2] && (val[1]+val[2]) == val[3])
            {
                printf("fibonacci sequence\n");
            }
            else
                // -> else return 1
                printf("none of the two\n");
                return 1;
        }  
    }
    return 0;
}
