/*
4. Implement the following string library functions using pointers:
                           string length (int StringLengh (char *s))
                           string copy (void StringCopy(char *s1, char *s2) )
                           string comparison (int StringCompare (char *s1, char *s2))
                           string concatenation (void StringConcat(char *s1, char *s2) )
*/


#include <stdio.h>

int Strlen(char *s)
{
    int len;
    for(len = 0; *s != '\0';len++)
        s++;
    return len;
}

void Strcpy(char *s1,char *s2)
{
    int i;

    for(i = 0; *s2 != '\0'; i++)
    {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
    
}

int Strcmp(char s1[],char s2[])
{
    int I, value = 0;

    for(i = 0; (*s1 != '\0' && *s2 != '\0'); i++)
    {
        if(s1[i] < s2[i])
        {
            value = -1;
            return -1;
        }
        else if(s1[i] > s2[i])
        {
            value =  1;
            return 1;
        }
    }
    if(*s1 == '\0')
      value = -1;
    else if(*s2 == '\0')
      value = 1;
    return value;
    
  
    
}

char tolower(char c)
{
    return c + 32;
}

int Strcasecmp(char s1[],char s2[])
{
    int i;

    for(i = 0; s1[i] != '\0'; i++)
        s1[i] = tolower(s1[i]);

    for(i = 0; s2[i] != '\0'; i++)
        s2[i] = tolower(s2[i]);

    for(i = 0; (s1[i] != '\0' && s2[i] != '\0'); i++)
    {
        if(tolower(s1[i]) == tolower(s2[i]))
            return 0;
        else if(tolower(s1[i]) > tolower(s2[i]))
            return 1;
        else if(tolower(s1[i]) < tolower(s2[i]))    
            return -1;
    }
}

void Strcat(char *s1, char *s2)
{
    int i;

    for(i = 0; s1[i] != '\0'; i++);

    for(i; s2[i] != '\0'; i++)
        s1[i] = s2[i];

}
