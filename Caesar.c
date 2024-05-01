#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main (int argc, char *argv[])
{


if(argc != 2)
{
printf("Usage: ./caesar key\n");
return -1;
}

for(int i=0, x = strlen(argv[1]); i < x; i++)
if( !isdigit(argv[1][i]))
{
printf("Usage: ./caesar key\n");
return -1;
}

int key = atoi(argv[1]); 
char plaintext[10000];
char ciphertext[10000];

printf("Plaintext: ");
fgets(plaintext,1000, stdin);

for(int i=0, x = strlen(plaintext); i < x; i++)
{
if(isalpha(plaintext[i]) && key >= 26)
ciphertext[i] = plaintext[i] + (key % 26);

else if(isalpha(plaintext[i]))
ciphertext[i] = plaintext[i] + key;

}

printf("Ciphertext: %s",ciphertext);

}
