#include <stdio.h>
#include <string.h>

char stack[20],item;
int top;

void push(char item)
{
    stack[++top] = item;
}

void pop()
{
    item = stack[top--];
}

int main()
{
    int i,palindrome = 1;
    top = -1;
    char str[20];

    printf("Enter a string: ");
    scanf(" %[^\n]",str);

    for(i = 0; str[i] != '\0'; i++)
		if(str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;

    for(i = 0; str[i] != '\0'; i++)
        push(str[i]);

    for(i = 0; str[i] != '\0'; i++)
    {
        palindrome = 1;
        pop();
        if(str[i] != item)
        {
            palindrome = 0;
            break;
        }
    }

    if(palindrome)
        printf("%s is a palindrome",str);
    else
        printf("%s is not a palindrome",str);
}