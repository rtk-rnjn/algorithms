#include <stdio.h>
#include <stdlib.h>

int is_operator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int perform_operation(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    default:
        return 0;
    }
}

struct stack
{
    int *data;
    int size;
    int capacity;
};

void stack_init(struct stack *s)
{
    s->size = 0;
    s->capacity = 4;
    s->data = (int *)malloc(sizeof(int) * s->capacity);
}

void stack_push(struct stack *s, int value)
{
    if (s->size >= s->capacity)
    {
        s->capacity *= 2;
        s->data = (int *)realloc(s->data, sizeof(int) * s->capacity);
    }
    s->data[s->size++] = value;
}

int stack_pop(struct stack *s)
{
    if (s->size == 0)
    {
        printf("Stack is empty\n");
        exit(1);
    }
    return s->data[--s->size];
}

int stack_peek(struct stack *s)
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

int evaluate_postfix(char *expression)
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    stack_init(s);

    for (int i = 0; expression[i]; i++)
    {
        if (is_operator(expression[i]))
        {
            int b = stack_pop(s);
            int a = stack_pop(s);
            int result = perform_operation(a, b, expression[i]);
            stack_push(s, result);
        }
        else
        {
            stack_push(s, expression[i] - '0');
        }
    }

    int result = stack_pop(s);
    stack_free(s);
    return result;
}

int main()
{
    char expression[] = "231*+9-"; // (2 + (3 * 1)) - 9
    printf("Result: %d\n", evaluate_postfix(expression));
    return 0;
}