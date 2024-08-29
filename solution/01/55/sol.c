#include <stdlib.h>

typedef struct {
    int* stack;
    int* minStack;
    int top;
    int minTop;
    int capacity;
} MinStack;

MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->capacity = 1000;
    obj->stack = (int*)malloc(sizeof(int) * obj->capacity);
    obj->minStack = (int*)malloc(sizeof(int) * obj->capacity);
    obj->top = -1;
    obj->minTop = -1;
    return obj;
}

void resizeStack(MinStack* obj) {
    obj->capacity *= 2;
    obj->stack = (int*)realloc(obj->stack, sizeof(int) * obj->capacity);
    obj->minStack = (int*)realloc(obj->minStack, sizeof(int) * obj->capacity);
}

void minStackPush(MinStack* obj, int val) {
    if (obj->top + 1 >= obj->capacity) {
        resizeStack(obj);
    }
    obj->stack[++obj->top] = val;

    if (obj->minTop == -1 || val <= obj->minStack[obj->minTop]) {
        obj->minStack[++obj->minTop] = val;
    }
}
void minStackPop(MinStack* obj) {
    if (obj->top == -1) return;
    int poppedValue = obj->stack[obj->top--];
    if (poppedValue == obj->minStack[obj->minTop]) {
        obj->minTop--;
    }
}

int minStackTop(MinStack* obj) {
    if (obj->top == -1) return -1;
    return obj->stack[obj->top];
}

int minStackGetMin(MinStack* obj) {
    if (obj->minTop == -1) return -1;
    return obj->minStack[obj->minTop];
}

void minStackFree(MinStack* obj) {
    free(obj->stack);
    free(obj->minStack);
    free(obj);
}