#include<cs50.h>
#include<stdio.h>
#include<math.h>

int main(void) {
    //Get change valeu
    float change;
    do {
        change = get_float("How much change? \n");     
    } while(change < 0);
    //round it 
    int coins = round(change * 100);
    //see how many 25 cents coins
    int twofive = coins / 25;
    int rest1 = coins % 25;
    //see how many 10 cents coins
    int ten = rest1 / 10;
    int rest2 = rest1 % 10;
    //see how many 5 cents coins
    int five = rest2 / 5;
    int rest3 = rest2 % 5;
    //see how many 1 cent coins
    int one = rest3;
    //output the results
    printf("Number of 25 cents coins: %i\n", twofive);
    printf("Number of 10 cents coins: %i\n", ten);
    printf("Number of 5 cents coins: %i\n", five);
    printf("Number of 1 cent coins: %i\n", one);
    
}
