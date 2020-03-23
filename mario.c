//Mario, problem set 1
#include <cs50.h>
#include <stdio.h>

int main(void)
{   int n = 0;
    //get height between 1 and 8
    do {
        n = get_int("Height:\n");
    } while(n < 1 || n > 8);
    //"Space counter" 1 + print blocks
    for(int i = 0; i < n - 1; i++) {
        printf(" ");
    }
    printf("#\n");
    //"Space counter" 2 + print blocks(using if clause)
    for(int i = 0; i < n - 2; i++) {
        printf(" ");
    }
    if(n > 1) printf("##\n");
    //"Space counter" 3 + print blocks(using if clause)
     for(int i = 0; i < n - 3; i++) {
        printf(" ");
    }
    if(n > 2) printf("###\n");
    //"Space counter" 4 + print blocks(using if clause)
     for(int i = 0; i < n - 4; i++) {
        printf(" ");
    }
    if(n > 3) printf("####\n");
    //"Space counter" 5 + print blocks(using if clause)
     for(int i = 0; i < n - 5; i++) {
        printf(" ");
    }
    if(n > 4) printf("#####\n");
    //"Space counter" 6 + print blocks(using if clause)
     for(int i = 0; i < n - 6; i++) {
        printf(" ");
    }
    if(n > 5) printf("######\n");
    //"Space counter" 7 + print blocks(using if clause)
     for(int i = 0; i < n - 7; i++) {
        printf(" ");
    }
    if(n > 6) printf("#######\n");
    //"Space counter" 8 + print blocks(using if clause)
     for(int i = 0; i < n - 8; i++) {
        printf(" ");
    }
    if(n > 7) printf("########\n");
}

