#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void escalera(int x);
int main(void)
{

int height;
do
{
printf("Altura de la escalera:");
scanf(" %d", &height);
if(isalpha(height))
{
printf("Please enter a number");
return -1;
}
}
while( height > 8 || height < 1 );

escalera(height);
}

void escalera(int x)
{
for (int a = 0; a < x; a++)
{
//More confortable
for(int z = a ; z < (x-1); z ++ )
printf(" ");

for (int m = 0; m < (a + 1); m++)
printf("#");


printf("  ");

//Less confortable
for (int m = 0; m < (a + 1); m++)
{
printf("#");
}

printf("\n");
}
}