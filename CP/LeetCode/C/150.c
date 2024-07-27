#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int evalRPN(const char **tokens, int tokensSize)
{
    int *stack = (int *)malloc(tokensSize * sizeof(int));
    int top = -1;

    for (int i = 0; i < tokensSize; i++)
    {
        if (isdigit(tokens[i][0]) || (tokens[i][0] == '-' && isdigit(tokens[i][1])))
        {
            stack[++top] = atoi(tokens[i]);
        }
        else
        {
            int b = stack[top--];
            int a = stack[top--];
            switch (tokens[i][0])
            {
            case '+':
                stack[++top] = a + b;
                break;
            case '-':
                stack[++top] = a - b;
                break;
            case '*':
                stack[++top] = a * b;
                break;
            case '/':
                stack[++top] = a / b;
                break;
            default:
                fprintf(stderr, "Error: unknown operator %s\n", tokens[i]);
                free(stack);
                return -1;
            }
        }
    }
    int result = stack[top];
    free(stack);
    return result;
}

int main()
{
    const char *tokens[] = {"2", "1", "+", "3", "*"};
    int tokensSize = 5;
    printf("%d\n", evalRPN(tokens, tokensSize));
    return 0;
}
