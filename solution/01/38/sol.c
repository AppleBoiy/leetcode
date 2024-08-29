struct Node* copyRandomList(struct Node* head) {
    if (head == NULL) return NULL;

    struct Node* current = head;
    while (current != NULL) {
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        copy->val = current->val;
        copy->next = current->next;
        copy->random = NULL;
        current->next = copy;
        current = copy->next;
    }

    current = head;
    while (current != NULL) {
        struct Node* copy = current->next;
        copy->random = (current->random != NULL) ? current->random->next : NULL;
        current = copy->next;
    }

    struct Node* newHead = head->next;
    struct Node* copy = newHead;
    current = head;
    while (current != NULL) {
        current->next = copy->next;
        current = current->next;
        if (current != NULL) {
            copy->next = current->next;
            copy = copy->next;
        }
    }

    return newHead;
}