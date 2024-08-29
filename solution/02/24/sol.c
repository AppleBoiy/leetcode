#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STACK_SIZE 10000

typedef struct {
    int items[MAX_STACK_SIZE];
    int top;
} Stack;

void initStack(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, int item) {
    if (stack->top < MAX_STACK_SIZE - 1) {
        stack->items[++(stack->top)] = item;
    }
}

int pop(Stack *stack) {
    if (isEmpty(stack)) {
        return 0;
    }
    return stack->items[(stack->top)--];
}

int calculate(const char *s) {
    Stack stack;
    initStack(&stack);
    int num = 0;
    int result = 0;
    int sign = 1;
    int currentSign = 1;

    while (*s) {
        if (isdigit(*s)) {
            num = num * 10 + (*s - '0');
        } else if (*s == '+') {
            result += currentSign * num;
            num = 0;
            currentSign = sign;
        } else if (*s == '-') {
            result += currentSign * num;
            num = 0;
            currentSign = -sign;
        } else if (*s == '(') {
            push(&stack, result);
            push(&stack, currentSign);
            result = 0;
            currentSign = 1;
        } else if (*s == ')') {
            result += currentSign * num;
            num = 0;
            result *= pop(&stack);
            result += pop(&stack);
        }
        s++;
    }

    result += currentSign * num;
    return result;
}
