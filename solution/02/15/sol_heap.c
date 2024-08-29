struct heap {
    int *data;
    int size;
    int capacity;
};

struct heap *heap_create(int capacity) {
    struct heap *h = malloc(sizeof(struct heap));
    h->data = malloc(sizeof(int) * (capacity + 1));
    h->size = 0;
    h->capacity = capacity;
    return h;
}

void heap_insert(struct heap *h, int value) {
    h->data[++h->size] = value;
    for (int i = h->size; i > 1; i /= 2) {
        if (h->data[i] < h->data[i / 2]) {
            int t = h->data[i];
            h->data[i] = h->data[i / 2];
            h->data[i / 2] = t;
        } else {
            break;
        }
    }
}

int heap_remove(struct heap *h) {
    int value = h->data[1];
    h->data[1] = h->data[h->size--];
    for (int i = 1; i * 2 <= h->size;) {
        int child = i * 2;
        if (child + 1 <= h->size && h->data[child + 1] < h->data[child]) {
            child++;
        }
        if (h->data[i] > h->data[child]) {
            int t = h->data[i];
            h->data[i] = h->data[child];
            h->data[child] = t;
            i = child;
        } else {
            break;
        }
    }
    return value;
}

int findKthLargest(int* nums, int numsSize, int k) {
    struct heap *h = heap_create(k);
    for (int i = 0; i < numsSize; i++) {
        if (h->size < k) {
            heap_insert(h, nums[i]);
        } else if (nums[i] > h->data[1]) {
            heap_remove(h);
            heap_insert(h, nums[i]);
        }
    }
    return h->data[1];
}