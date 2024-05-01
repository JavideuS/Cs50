#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int compute_score(char word[]);

int main(void)
{
char player1[100];
char player2[100];

printf("Player 1:");
scanf(" %s", player1);

printf("Player 2:");
scanf(" %s", player2);

int score1 = compute_score(player1);
int score2 = compute_score(player2);

if(score1 > score2)
printf("Player 1 wins");
else if(score1 < score2)
printf("Player 2 wins");
else
printf("It's a tie");
}

int compute_score(char word[])
{

int points [] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};

int score = 0;

for(int zz = 0, len = strlen(word); zz < len; zz++)
if(isupper(word[zz]))
score += points[word[zz] - 'A'];
else if(islower(word[zz]))
score += points[word[zz] - 'a'];


return score;
}