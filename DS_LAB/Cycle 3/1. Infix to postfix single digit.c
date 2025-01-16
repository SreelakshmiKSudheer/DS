#include <stdio.h>
#include <string.h>
#include <math.h>

#define SIZE 20
#define INVALID '\0'
#define FINVALID -99999.999

float fstack[SIZE];
char cstack[SIZE];
int ftop = -1, ctop = -1;

void fpush(float item)
{
    if(ftop == SIZE-1)
        printf("Stack overflow\n");
    else    
        fstack[++ftop] = item;
}

float fpop()
{
    if(ftop == -1)
        printf("Stack underflow\n");
    else
        return fstack[ftop--];
}

void cpush(char item)
{
    if(ctop == SIZE-1)
        printf("Stack overflow\n");
    else    
        cstack[++ctop] = item;
}

char cpop()
{
    if(ctop == -1)
        printf("Stack underflow\n");
    else
        return cstack[ctop--];
}

int operand(char c)
{
    if(c >= '0' && c <= '9')
        return 1;
    return 0;
}

int icp(char c)
{
    switch(c)
    {
        case '+':
        case '-': return 1;

        case '*': 
        case '/': return 3;

        case '^': return 6;

        case '(': return 7;
        case ')': return 0;
    }
}

int isp(char c)
{
    switch(c)
    {
        case '+':
        case '-': return 2;

        case '*': 
        case '/': return 4;

        case '^': return 5;

        case '(': return 0;
        
    }
}

float calculate(float a,float b,char op)
{
    float result;

    switch(op)
    {
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;

        case '/': if(b == 0)
                    return FINVALID;
                  else
                    return a/b;
        case '^': return pow(a,b);

        default : return FINVALID;

    }
}

int main()
{
    char infix[20],postfix[20],op,item,x;
    int i,j,citem;
    float result,a,b;

    printf("Enter an infix expression: \n");
    scanf(" %[^\n]",infix);

    for(i = 0; infix[i] != '\0'; i++);
    infix[i] = ')';

    cpush('(');

    i = 0;j = 0;

    while(ctop >- 1)
    {
        item = infix[i++];
        x = cpop();

        if(operand(item))
        {
            postfix[j++] = item;
            cpush(x); 
        }
        else if(item == ')')
        {
            while(x != '(')
            {
                postfix[j++] = x;
                x = cpop();
            }
        }
        else if(isp(x) >= icp(item))
        {
            while(isp(x) >= icp(item))
            {
                postfix[j++] = x;
                x = cpop();
            }
            cpush(x);
            cpush(item);
        }
        else if(isp(x) < icp(item))
        {
            cpush(x);
            cpush(item);
        }
    }

    postfix[j] = '\0';
    printf("\nPostfix expression:\n");
    printf("%s\n",postfix);

    postfix[j++] = '#';
    postfix[j++] = '\0';

    i = 0;
    citem = postfix[i++];

    while(citem != '#')
    {
        if(operand(citem))
            fpush(citem - '0');
        else
        {
            op = citem;
            b = fpop();
            a = fpop();
            result = calculate(a,b,op);
            fpush(result);
        }
        citem = postfix[i++];
    }
    result = fpop();
    printf("\n\nResult = %.2f\n",result);

}
