#include <cs50.h>
#include <stdio.h>
#include <math.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{

    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents -=  quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents -=  dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents -=  nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents -=  pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("Minimum coins:%i\n", coins);
}

int get_cents(void)
{
    // TODO
int cents;
do
{
printf("Change owed:");
scanf(" %d", &cents);
}
while(cents < 0);
    return cents;
}

int calculate_quarters(int cents)
{
    // TODO
int quarters = floor(cents / 25);

    return quarters;
}

int calculate_dimes(int cents)
{
    // TODO
int dimes = floor(cents / 10);

    return dimes;
}

int calculate_nickels(int cents)
{
    // TODO
int nickels = floor(cents / 5);

    return nickels;
}

int calculate_pennies(int cents)
{
   int pennies = cents / 1;

    return pennies;
}
