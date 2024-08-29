#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 1000003

typedef struct {
    int key;
    int value;
} HashItem;

typedef struct {
    HashItem* items;
} HashTable;

HashTable* createHashTable() {
    HashTable* table = malloc(sizeof(HashTable));
    table->items = (HashItem*)calloc(TABLE_SIZE, sizeof(HashItem));
    return table;
}

unsigned int hash(const int key) {
    return key % TABLE_SIZE;
}

void insert(const HashTable* table, const int key, const int value) {
    unsigned int index = hash(key);
    while (table->items[index].key != 0 && table->items[index].key != key) {
        index = (index + 1) % TABLE_SIZE;
    }
    table->items[index].key = key;
    table->items[index].value = value;
}

int search(const HashTable* table, const int key) {
    unsigned int index = hash(key);
    while (table->items[index].key != 0) {
        if (table->items[index].key == key) {
            return table->items[index].value;
        }
        index = (index + 1) % TABLE_SIZE;
    }
    return 0;
}

void freeHashTable(HashTable* table) {
    free(table->items);
    free(table);
}

static int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int countPairs(int* nums, const int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    int ans = 0;
    HashTable* table = createHashTable();

    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];
        int vis[1000000] = {0};
        vis[x] = 1;
        char s[12];
        sprintf(s, "%d", x);

        const int len = strlen(s);
        for (int j = 0; j < len; j++) {
            for (int k = 0; k < j; k++) {
                const char temp = s[k];
                s[k] = s[j];
                s[j] = temp;
                const int v = atoi(s);
                vis[v] = 1;
                // Swap back
                s[j] = s[k];
                s[k] = temp;
            }
        }
        for (int v = 0; v < 1000000; v++) {
            if (vis[v]) {
                ans += search(table, v);
            }
        }
        insert(table, x, search(table, x) + 1);
    }

    freeHashTable(table);
    return ans;
}

int main()
{
    int nums[] = {1, 1, 1, 1, 1}; //10
    const int numsSize = sizeof(nums) / sizeof(nums[0]);
    printf("%d\n", countPairs(nums, numsSize));
    return 0;
}