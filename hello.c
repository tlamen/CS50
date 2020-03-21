//Problem set 1, part 0: hello.c

#include <stdio.h>
#include <cs50.h>

//main method
int main(void)
{ 
    string answer = get_string("What's your name?");
    printf("hello, %s\n", answer);
}
