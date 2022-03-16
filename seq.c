#include <cs50.h>
#include <stdio.h>
#include <string.h>

int check(float val[], int c);
int c_f(float val[], int c);
int n_s(int x, float val_a[], float val_b[], int s);
int fct_p(char a, int x, float val_a[], float val_b[], int s);
void more_work(int x, float val_a[], float val_b[], int s);
void guess(int x, float val_a[], float val_b[], int s);

int main(void) {
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
    
    return 0;
}

// fct check
int check(float val[], int c) {
    int s = c-2, i = 1, j = 0, cas;
    float geom[s], arithm[s], fibo[s]; 

    while(i<c && j<c-1) {
        // arithm
        arithm[j] = val[i] - val[j];
        // geom
        geom[j] = val[i] / val[j];
        i++, j++;
    }

    // -> if geom -- next 
    if(c_f(geom, s) == 0) {
        cas = 1;
        printf("Geometric sequence\n");
        n_s(cas, val, geom, c);
    }
    else {

        // -> else arithm -- next 
        if(c_f(arithm, s) == 0) {
            cas = 2;
            printf("Arithmetic sequence\n");
            n_s(cas, val, arithm, c);
        } 
        else {
            for (int i = 0; i < c; i++)
                fibo[i] = val[i];

            // -> else fibo -- next 
            if (c_f(fibo, s) == 0) {
                cas = 3;
                printf("Fibonacci sequence\n");
                n_s(cas, val, fibo, c);
            }
            else {

                // -> else return 1
                printf("Sorry, this sequence does not belong to any of the three I have.\n");
                return 1;
            }
        }  
    }
    return 0;
}

// check if g or a or f true or false
int c_f(float val[], int c) {
    int i, t = 0, f = 0;

    for (i = 0; i < c; i++)
    {
        if (val[i] == val[i+1] || (val[i] + val[i+1]) == val[i+2]) t++;
        else f++;
    }
    return f;
}

// ask for more work
int n_s(int x, float val_a[], float val_b[], int s) {  
    char f_next = get_char("Do you have more work for me?Y/N. ");
    fct_p(f_next, x, val_a, val_b, s);
    return 0;
}

// call for more work
int fct_p(char a, int x, float val_a[], float val_b[], int s) {

    if (a == 'n' || a == 'N') {
        printf("Goodbye!\n");
        return 0;

    } else if (a == 'y' || a == 'Y') more_work(x, val_a, val_b, s);

    else {
        char new = get_char("Please answer correctly!\nDo You have more work for me? (Y) for yes/ (N) for no ..\nY/N? ");
        fct_p(new, x, val_a, val_b, s);
    }
    return 0;
}

// choices for more work
void more_work(int x, float val_a[], float val_b[], int s) {
    printf("What can I do for You\n(1)-> Check one more sequence\n(2)-> Guess the nth number\n");

    int v = get_int("Choice: ");

    if (v == 1) 
        main();

    else if (v == 2) 
        guess(x, val_a, val_b, s);

    else {
        printf("\nPlease choose only from one of the choices!\n");
        more_work(x, val_a, val_b, s);
    }
}

// guessing the nth position
void guess(int x, float val_a[], float val_b[], int s) {

    int new = get_int("please give the nth position you desire to find: ");

    int p_val = 1, new_v, val_v[new], new_s = new - 2;

    if (x == 1) {
        for (int i = 0; i < new_s; i++)
            p_val *= val_b[0];

        // g: -> x(n) = x(1)r^(n-1)
        new_v = val_a[1] * p_val;
        printf("%i\n", new_v);

    } else if (x == 2) {

        // a: -> x(n) = x(1) + (n-1)(d)
        new_v = val_a[1] + ((new_s) * val_b[0]);
        printf("%i\n", new_v);

    } else {
        for (int i = 0; i < s; i++)
            val_v[i] = val_a[i];

        
        for (int i = s; i < new; i++)

            // f: -> x(n) = x(n-1) + x(n-2)
            val_v[i] = val_v[i-1] + val_v[i-2];
        printf("%i \n", val_v[new-1]);
    }
}
