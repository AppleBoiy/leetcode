char * mergeAlternately(char * word1, char * word2){
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int len = len1 + len2;
    char *res = (char *)malloc(len + 1);
    int i = 0, j = 0, k = 0;
    while (i < len1 && j < len2) {
        res[k++] = word1[i++];
        res[k++] = word2[j++];
    }
    while (i < len1) {
        res[k++] = word1[i++];
    }
    while (j < len2) {
        res[k++] = word2[j++];
    }
    res[k] = '\0';
    return res;
}