#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {
    char** res = NULL;
    int resSize = 0;
    int i = 0;
    
    while (i < wordsSize) {
        int j = i, len = 0;
        while (j < wordsSize && len + strlen(words[j]) + j - i <= maxWidth) {
            len += strlen(words[j++]);
        }
        
        int spaces = maxWidth - len;
        int slots = j - i - 1;
        char* line = (char*)malloc((maxWidth + 1) * sizeof(char));
        line[0] = '\0';
        
        if (j == wordsSize || slots == 0) {
            for (int k = i; k < j; k++) {
                strcat(line, words[k]);
                if (k < j - 1) strcat(line, " ");
            }
            int remainingSpaces = maxWidth - strlen(line);
            for (int l = 0; l < remainingSpaces; l++) {
                strcat(line, " ");
            }
        } else {
            int evenSpaces = spaces / slots;
            int extraSpaces = spaces % slots;
            for (int k = i; k < j; k++) {
                strcat(line, words[k]);
                if (k < j - 1) {
                    for (int l = 0; l < evenSpaces + (k - i < extraSpaces ? 1 : 0); l++) {
                        strcat(line, " ");
                    }
                }
            }
        }
        
        res = (char**)realloc(res, (resSize + 1) * sizeof(char*));
        res[resSize++] = line;
        i = j;
    }
    
    *returnSize = resSize;
    return res;
}
