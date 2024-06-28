#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char value)
{
    if (top < MAX - 1)
    {
        stack[++top] = value;
    }
}

char pop()
{
    if (top >= 0)
    {
        return stack[top--];
    }
    return '\0';
}

// for checking the operator in the expression or infix stack
int operator(char value)
{
    if (value == '+' || value == '-' || value == '/' || value == '*' || value == '^')
    {
        return 1;
    }
    return 0;
}

// checking the precendence of the operator
int rank(char value)
{
    if (value == '+' || value == '-')
    {
        return 1;
    }
    else if (value == '/' || value == '*')
    {
        return 2;
    }
    else if (value == '^')
    {
        return 3;
    }
    else
    {
        return 0;
    }
}

void infixToPostfix(char inf[], char post[])
{
    int i = 0, j = 0;

    while (inf[i] != '\0')
    {

        char value = inf[i];

        if (isalnum(value))
        {
            post[j++] = value;
        }
        else if (value == '(')
        {
            push(value);
        }
        else if (value == ')')
        {
            char popele = pop();
            while (popele != '(')
            {
                post[j++] = popele;
                popele = pop();
            }
        }
        else if (operator(value))
        {
            while (top >= 0 && rank(stack[top]) >= rank(value))
            {
                post[j++] = pop();
            }
            push(value);
        }
        i++;
    }
     // for checking that all the elements of infix are transferred to postfix
    while (top >= 0)
    {
        post[j++] = pop();
    }
    post[j] = '\0';
}

int main()
{

    // for storing expression i.e. infix stack
    char inf[MAX];

    // for storing expression i.e. postfix stack
    char post[MAX];

    printf("Enter the expression :\t");
    scanf("%s", inf);

    infixToPostfix(inf, post);
    printf("%s", post);

    return 0;
}
