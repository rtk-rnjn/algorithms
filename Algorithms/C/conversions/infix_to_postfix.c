#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    char *data;
    int size;
    int capacity;
};

void stack_init(struct stack *s)
{
    s->size = 0;
    s->capacity = 4;
    s->data = malloc(sizeof(char) * s->capacity);
}

void stack_push(struct stack *s, char value)
{
    if (s->size >= s->capacity)
    {
        s->capacity *= 2;
        s->data = realloc(s->data, sizeof(char) * s->capacity);
    }
    s->data[s->size++] = value;
}

char stack_pop(struct stack *s)
{
    if (s->size == 0)
    {
        printf("Stack is empty\n");
        exit(1);
    }
    return s->data[--s->size];
}

char stack_peek(struct stack *s)
{
    if (s->size == 0)
    {
        printf("Stack is empty\n");
        exit(1);
    }
    return s->data[s->size - 1];
}

void stack_free(struct stack *s)
{
    free(s->data);
    s->data = NULL;
    s->size = 0;
    s->capacity = 0;
    free(s);
    s = NULL;
}

int stack_length(struct stack *s)
{
    return s->size;
}

void display(struct stack *s)
{
    for (int i = 0; i < stack_length(s); i++)
    {
        printf("%c ", s->data[i]);
    }
    printf("\n");
}

int precedence(char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }
    if (op == '*' || op == '/')
    {
        return 2;
    }
    return 0;
}

char *infix_to_postfix(char *infix)
{
    struct stack *s = malloc(sizeof(struct stack));
    stack_init(s);
    char *postfix = malloc(sizeof(char) * ((int)strlen(infix) + 1));
    int j = 0;
    for (int i = 0; infix[i]; i++)
    {
        if (infix[i] >= '0' && infix[i] <= '9')
        {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            stack_push(s, infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (stack_length(s) && stack_peek(s) != '(')
            {
                postfix[j++] = stack_pop(s);
            }
            stack_pop(s);
        }
        else
        {
            while (stack_length(s) && precedence(stack_peek(s)) >= precedence(infix[i]))
            {
                postfix[j++] = stack_pop(s);
            }
            stack_push(s, infix[i]);
        }
    }
    while (stack_length(s))
    {
        postfix[j++] = stack_pop(s);
    }
    postfix[j] = '\0';
    stack_free(s);
    return postfix;
}

int main()
{
    char *infix = "1+2*3";
    char *postfix = infix_to_postfix(infix);
    printf("%s\n", postfix);
    free(postfix);
    return 0;
}
