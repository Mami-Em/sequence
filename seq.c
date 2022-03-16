#include <cs50.h>
#include <stdio.h>
#include <string.h>

int check(float val[], int c);
int c_f(float val[], int c);
int next(char a);
void more_work();
void guess() {
    printf("Fct guess on its way\n");
}

int main(void) {
    // get input
    int clue = get_int("\nHow many numbers do you have? ");
    // reurn 1 if number fewer than 3
    if (clue < 3)
    {
        printf("The number inserted should be more or equal to three.\n");
        return 1;
    }
    // new empt arr
    float tab[clue];
    
    for (int i = 0; i<clue; i++) 
        // insert values in new arr
        tab[i] = get_int("number n %i: ", i+1);
    // check the seq
    check(tab, clue);
    // ask for more
    char f_next = get_char("Do you have more work for me?Y/N. ");
    next(f_next);
    return 0;
}

int check(float val[], int c) {
    int s = c-2, i = 1, j = 0;
    float geom[s], arithm[s], fibo[s]; 
    while(i<c && j<c-1) {
        arithm[j] = val[i] - val[j];
        geom[j] = val[i] / val[j];
        i++, j++;
    }

    // -> if geom -- next seq and proof
    if(c_f(geom, s) == 0)
        printf("geometric sequence\n");
    else {
        // -> else arithm -- next seq and proof
        if(c_f(arithm, s) == 0)
            printf("arithmetic sequence\n");
        else {
            for (int i = 0; i < c; i++)
                fibo[i] = val[i];
            // -> else fibo -- next seq and proof
            if (c_f(fibo, s) == 0)
            {
                printf("fibonacci sequence\n");
            }
            else
                // -> else return 1
                printf("none of the three\n");
                return 1;
        }  
    }
    return 0;
}
// f: -> x(n) = x(n-1) + x(n-2)
// g: -> x(n) = x(1)r^(n-1)
// a: -> x(n) = x(1) + x(n-1)(r)
int c_f(float val[], int c) {
    int i, t = 0, f = 0;
    for (i = 0; i < c; i++)
    {
        if (val[i] == val[i+1] || (val[i] + val[i+1]) == val[i+2]) t++;
        else f++;
    }
    return f;
}

int next(char a) {
    if (a == 'n' || a == 'N') {
        printf("Goodbye!\n");
        return 0;
    } else if (a == 'y' || a == 'Y') more_work();
    else {
        char new = get_char("Please answer correctly!\nDo You have more work for me? (Y) for yes/ (N) for no ..\nY/N? ");
        next(new);
    }
    return 0;
}

void more_work() {
    printf("How can I help You?\n(1)-> Check one more sequence\n(2)-> Guess the nth number\n");
    int v = get_int("Choice: ");
    if (v == 1) 
        main();
    else if (v == 2) 
        guess();
    else {
        printf("Please choose only from one of the choices!\n");
        more_work();
    }
}
