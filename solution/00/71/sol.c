#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* simplifyPath(char* path) {
    char* stack[1000];
    int top = -1;
    char* p = path;

    while (*p) {
        if (*p == '/') {
            p++;
            continue;
        }
        if (*p == '.') {
            if (*(p + 1) == '.' && (*(p + 2) == '/' || *(p + 2) == '\0')) {
                if (top >= 0) {
                    top--;
                }
                p += 2;
            } else if (*(p + 1) == '/' || *(p + 1) == '\0') {
                p++;
            } else {
                stack[++top] = p;
                while (*p && *p != '/') {
                    p++;
                }
            }
        } else {
            // Regular directory name
            stack[++top] = p;
            while (*p && *p != '/') {
                p++;
            }
        }
    }

    char* result = (char*)malloc(sizeof(char) * 1000);
    char* q = result;
    if (top == -1) {
        *q++ = '/';
    } else {
        for (int i = 0; i <= top; i++) {
            *q++ = '/';
            char* temp = stack[i];
            while (*temp && *temp != '/') {
                *q++ = *temp++;
            }
        }
    }

    *q = '\0';
    return result;
}