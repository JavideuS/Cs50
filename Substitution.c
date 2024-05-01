#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Texto de prueba: jtrekyavogdxpsncuizlfbwhq // JTREKYAVOGDXPSNCUIZLFBWHQ

int main (int argc, char *argv[])
{
//Command-line argument
if(argc != 2 )
{
printf("Usage: ./substitution key");
return -1;
}
else if(strlen(argv[1]) < 25 || strlen(argv[1]) >= 27 )
{
printf("Key must contain 26 characters");
return -1;
} 
for(int i=0, x = strlen(argv[1]); i < x; i++)
{
if(!isalpha(argv[1][i]) )
{
printf("Key must contain 26 characters and must be letters");
return -1;
}
}

for(int z=0, a = 1; z < 26; z++)
{
//z+1 porque asi a siempre sera mayor que z
for(int a= z+1; a < 26; a++)
{
if(argv[1][z] == argv[1][a])
{
printf("Key must contain 26 different characters");
return -1;
}
}

}

//Texto
char plaintext[10000];
char alphabet [26];
printf("Plaintext: ");
fgets(plaintext,1000, stdin);
printf("Ciphertext: ");

//Codigo
for(int i=0; i <26; i++)
alphabet[i] = argv[1][i];

for(int i=0, x = strlen(plaintext); i < x; i++)
{
for(int z=0; z < 26; z++)
{
if(plaintext[i] == 'A' + z )
printf("%c", toupper(alphabet[z]));
else if(plaintext[i] == 'a' + z )
printf("%c", tolower(alphabet[z]));
}
if(!isalpha(plaintext[i]))
printf("%c", plaintext[i]);
}


}