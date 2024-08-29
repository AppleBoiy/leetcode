int evalRPN(char** tokens, int tokensSize) {
    int stack[10000];
    int top = -1;
    for (int i = 0; i < tokensSize; i++) {
        if (tokens[i][0] >= '0' && tokens[i][0] <= '9' || tokens[i][0] == '-' && tokens[i][1] != '\0') {
            stack[++top] = atoi(tokens[i]);
        } else {
            int b = stack[top--];
            int a = stack[top--];
            if (tokens[i][0] == '+') {
                stack[++top] = a + b;
            } else if (tokens[i][0] == '-') {
                stack[++top] = a - b;
            } else if (tokens[i][0] == '*') {
                stack[++top] = a * b;
            } else if (tokens[i][0] == '/') {
                stack[++top] = a / b;
            }
        }
    }
    return stack[top];
}