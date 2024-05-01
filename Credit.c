#include <stdio.h>
#include <math.h>

void typecard(long long x);
int length(long long x);
int validity(long long z);

//4003600000000014

int main(void) 
{
long long cardNumber;
printf("Credit card Number:");
scanf(" %lld", &cardNumber);
length(cardNumber);
int checksum = validity(cardNumber);

if(checksum % 10 == 0)
typecard(cardNumber);
else
printf("Invalid CreditCard");

}

int length(long long x)
{
int len;

for(len = 0; x > 0; x /= 10)
len+=1;

return len;
}

int validity(long long z)
{
int secondigits[length(z)];
int otherdigits = 0;
int digitsx = 0;

for(int m=0, x = length(z); m < x; m++, z /= 10)
{
if( m % 2 == 1)
{
secondigits[m] = 2*(z % 10);
if(secondigits[m] >= 10)
{
digitsx += secondigits[m] % 10;
digitsx += floor(secondigits[m] / 10); //Esto es basicamente un ++
}
else
digitsx += secondigits[m];
}

else
otherdigits += z % 10;
}
int checksum = digitsx + otherdigits;

return checksum;
}

void typecard(long long x)
{

if(length(x) == 15 )
{

int xx = length(x) - 2;

for(int m = 0; m < xx; m++)
{|
x /= 10;
}

if(x == 34 || x == 37)
printf("Valid, American Express creditCard");
}

else if(length(x) == 16 )
{

int xx = length(x) - 2;

for(int m = 0; m < xx; m++)
x /= 10;

if(x == 22 || x == 51 || x == 52 || x == 53 || x == 54 || x == 55)
printf("Valid, MasteCard creditCard");
else
{
x /= 10;
if(x == 4)
printf("Valid, Visa creditCard");
}
}

else if(length(x) == 13 )
{

int xx = length(x) - 1;

for(int m = 0; m < xx; m++)
x /= 10;

if(x == 4)
printf("Valid, Visa creditCard");
}

else
printf("Invalid CreditCard");

}

