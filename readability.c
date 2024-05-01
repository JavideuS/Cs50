#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(char text[]);
int count_words(char text[]);
int count_sentences(char text[]);
double words(char text[]);
double letters(char text[]);
double sentences(char text[]);

int main(void)
{
char texto[1000];

printf("Text: ");
fgets(texto, 1000, stdin);

count_letters(texto);
printf("\n");
count_words(texto);
printf("\n");
count_sentences(texto);
printf("\n");


double index;
double L = (letters(texto) / words(texto)) * 100.0 ;
double S = (sentences(texto) / words(texto)) * 100.0 ;
index = (0.0588 * L) - (0.296 * S) - (15.8);


if(round(index) <= 1)
printf("Before Grade 1");
else if(round(index) >= 16)
printf("Grade 16+");
else
printf("Grade %lf", round(index));

}

int count_letters(char text[])
{
int letters = 0;
/* La forma que se me ocurrio a mi
for(int i = 0, x = strlen(text);i < x; i++)
{
if(text[i] >= 'A' && text[i] <= 'Z')
letters++;
else if(text[i] >= 'a' && text[i] <= 'z')
letters++;
}
*/
//La forma mas eficiente
for(int i = 0, x = strlen(text);i < x; i++)
{
    
if( isalnum(text[i]))
letters++;
}

printf("%d letters",letters);

}
double letters(char text[])
{
int letters = 0;
for(int i = 0, x = strlen(text);i < x; i++)
if( isalnum(text[i]))
letters++;

return letters;
}
int count_words(char text[])
{
int words = 0;
for(int i= 0, x = strlen(text); i < x; i++)
if(isspace(text[i]) && isspace(text[i]) != isspace(text[i+1]))
words++;

if(isspace(text[0]))
words--;

printf("%d words", words);

}
double words(char text[])
{
int words = 0;
for(int i= 0, x = strlen(text); i < x; i++)
if(isspace(text[i]) && isspace(text[i]) != isspace(text[i+1]))
words++;

if(isspace(text[0]))
words--;
return words;
}
int count_sentences(char text[])
{
int sentences = 0;

for(int i = 0, x = strlen(text); i < x; i++)
{
if(text[i] == '.' || text[i] == '!' || text[i] == '?')
sentences++;
}

if(text[strlen(text)-2] != '.' && text[strlen(text)-2] != '!' && text[strlen(text)-2] != '?' && text[strlen(text)-2] != '"')
sentences++;

printf("%d sentences", sentences);
}
double sentences(char text[])
{
int sentences = 0;

for(int i = 0, x = strlen(text); i < x; i++)
{
if(text[i] == '.' || text[i] == '!' || text[i] == '?')
sentences++;
}

if(text[strlen(text)-2] != '.' && text[strlen(text)-2] != '!' && text[strlen(text)-2] != '?' && text[strlen(text)-2] != '"')
sentences++;

return sentences;
}