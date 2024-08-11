#include <stdio.h>   
#include <ctype.h>   

#define MAX 100    

// Stack and a variable to keep track of the top element
char stack[MAX];
int top = -1;

// Function to push an element onto the stack
void push(char value)
{
    if (top < MAX - 1)   // Check if there's space in the stack
    {
        stack[++top] = value;   // Increment the top and add the value to the stack
    }
}

// Function to pop an element from the stack
char pop()
{
    if (top >= 0)   // Check if the stack is not empty
    {
        return stack[top--];   // Return the top element and decrement the top
    }
    return '\0';   // Return null character if stack is empty
}

// Function to check if a character is an operator
int operator(char value)
{
    if (value == '+' || value == '-' || value == '/' || value == '*' || value == '^')
    {
        return 1;   // Return 1 if the character is an operator
    }
    return 0;   // Return 0 if it's not an operator
}

// Function to determine the precedence of operators
int rank(char value)
{
    if (value == '+' || value == '-')
    {
        return 1;   // Lowest precedence for + and -
    }
    else if (value == '/' || value == '*')
    {
        return 2;   // Medium precedence for / and *
    }
    else if (value == '^')
    {
        return 3;   // Highest precedence for ^
    }
    else
    {
        return 0;   // Return 0 for non-operator characters
    }
}

// Function to convert an infix expression to postfix
void infixToPostfix(char inf[], char post[])
{
    int i = 0, j = 0;

    // Loop through the infix expression
    while (inf[i] != '\0')
    {
        char value = inf[i];   // Get the current character

        if (isalnum(value))   // If the character is alphanumeric (operand)
        {
            post[j++] = value;   // Add it to the postfix expression
        }
        else if (value == '(')   // If it's an opening parenthesis
        {
            push(value);   // Push it onto the stack
        }
        else if (value == ')')   // If it's a closing parenthesis
        {
            char popele = pop();   // Pop from the stack until an opening parenthesis is found
            while (popele != '(')
            {
                post[j++] = popele;   // Add the popped operators to the postfix expression
                popele = pop();
            }
        }
        else if (operator(value))   // If it's an operator
        {
            // Pop operators with higher or equal precedence from the stack
            while (top >= 0 && rank(stack[top]) >= rank(value))
            {
                post[j++] = pop();
            }
            push(value);   // Push the current operator onto the stack
        }
        i++;
    }

    // Pop the remaining operators from the stack and add them to the postfix expression
    while (top >= 0)
    {
        post[j++] = pop();
    }
    post[j] = '\0';   // Null-terminate the postfix expression
}

int main()
{
    // Arrays to store the infix and postfix expressions
    char inf[MAX];
    char post[MAX];

    // Prompt the user to enter an infix expression
    printf("Enter the expression :\t");
    scanf("%s", inf);

    // Convert the infix expression to postfix
    infixToPostfix(inf, post);
    printf("%s", post);   // Print the postfix expression

    return 0;
}
