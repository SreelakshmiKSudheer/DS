#include <stdio.h>
#include <string.h>

int main()
{
	int count[50],i,j,k,x = 0,y = 0,appeared = 0,large,pos;
	char string[100],word[20],substring[50][20];

	printf("Enter a string without any whitespace characters(whitespace/carriage return/tab space): \n");
	scanf(" %[^\n]",string);

	for(i = 0; string[i] != '\0'; i++)
		if(string[i] >= 'A' && string[i] <= 'Z')
			string[i] += 32;
	
	for(i = 0; string[i] != '\0'; i++)
	{
		x = 0;
		count[y] = 0;
		word[x++] = string[i];
		count[y]++;
		for(j = i+1; string[j] != '\0'; j++)
		{
			appeared = 0;

			for(k = 0; k < x; k++)
			{
				if(word[k] == string[j])
				{
					appeared = 1;
					//word[x] = '\0';
					break;
				}
			}

			if(appeared)
				break;
			else
			{
				word[x++] = string[j];
				count[y]++;
			}
		}
		word[x] = '\0';
		strcpy(substring[y],word);
		y++;
	}

/*
	for(i = 0; i < y; i++)
		printf("%s\n",substring[i]);
*/

	large = count[0];
	for(i = 0; i < y; i++)
	{
		if(count[i] > large)
		{
			large = count[i];
			pos = i;
		}
	}

	printf("\nThe largest substring is \"%s\" with %d characters.\n",substring[pos],large);
}
