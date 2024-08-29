static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class RandomizedSet {
private:
    unordered_map<int, int> sn;

public:
    RandomizedSet() {}

    bool insert(int val) {
        if (sn.find(val) != sn.end()) {
            return false;
        }
        sn[val] = 1;
        return true;
    }

    bool remove(int val) {
        if (sn.find(val) == sn.end()) {
            return false;
        }
        sn.erase(val);
        return true;
    }

    int getRandom() {
        auto it = sn.begin();
        advance(it, rand() % sn.size());
        return it->first;
    }
};
