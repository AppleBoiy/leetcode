struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;

    Node()
    : key(0), value(0), prev(nullptr), next(nullptr) {}
    Node(int key, int value)
    : key(key), value(value), prev(nullptr), next(nullptr) {}
};



class LRUCache {
public:
    LRUCache(int capacity) {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
        this->capacity = capacity;
    }

    int get(int key) {
        if (map.find(key) == map.end()) {
            return -1;
        }

        Node* node = map[key];
        node->prev->next = node->next;
        node->next->prev = node->prev;

        head->next->prev = node;
        node->next = head->next;
        head->next = node;
        node->prev = head;

        return node->value;
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            Node* node = map[key];
            node->value = value;
            node->prev->next = node->next;
            node->next->prev = node->prev;

            head->next->prev = node;
            node->next = head->next;
            head->next = node;
            node->prev = head;
        } else {
            if (map.size() == capacity) {
                Node* node = tail->prev;
                node->prev->next = tail;
                tail->prev = node->prev;
                map.erase(node->key);
                delete node;
            }

            Node* node = new Node(key, value);
            head->next->prev = node;
            node->next = head->next;
            head->next = node;
            node->prev = head;
            map[key] = node;
        }
    }
private:

    Node* head;
    Node* tail;
    std::unordered_map<int, Node*> map;
    int capacity;
};