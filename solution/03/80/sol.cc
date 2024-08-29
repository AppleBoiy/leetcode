#include <random>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

class RandomizedSet {
private:
    unordered_map<int, int> valToIndex;
    vector<int> vals;
    int size = 0;
    mt19937 gen{random_device{}()};

    void swap(int i, int j) {
        int tmp = vals[i];
        vals[i] = vals[j];
        vals[j] = tmp;
        valToIndex[vals[i]] = i;
        valToIndex[vals[j]] = j;
    }
public:
    RandomizedSet() {}

    bool insert(int val) {
        if (valToIndex.find(val) != valToIndex.end()) {
            return false;
        }
        if (size == vals.size()) {
            vals.push_back(val);
        } else {
            vals[size] = val;
        }
        valToIndex[val] = size;
        size++;
        return true;
    }

    bool remove(int val) {
        if (valToIndex.find(val) == valToIndex.end()) {
            return false;
        }
        int index = valToIndex[val];
        swap(index, size - 1);
        valToIndex.erase(val);
        size--;
        return true;
    }

    int getRandom() {
        return vals[gen() % size];
    }

};


void testRandomizedSet() {
    RandomizedSet* obj = new RandomizedSet();

    assert(obj->insert(1) == true);
    assert(obj->insert(1) == false);
    assert(obj->remove(1) == true);
    assert(obj->remove(1) == false);
    assert(obj->insert(2) == true);
    assert(obj->insert(3) == true);

    int randomValue = obj->getRandom();
    assert(randomValue == 2 || randomValue == 3);
    assert(obj->remove(2) == true);

    randomValue = obj->getRandom();
    assert(randomValue == 3);
    delete obj;
}
