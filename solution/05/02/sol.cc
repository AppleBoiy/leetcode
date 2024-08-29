static auto _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Heap {
public:
    Heap() {
        data_.push_back(0);
    }

    void push(int x) {
        data_.push_back(x);
        int i = data_.size() - 1;
        while (i > 1) {
            int p = i / 2;
            if (data_[p] < data_[i]) {
                swap(data_[p], data_[i]);
                i = p;
            } else {
                break;
            }
        }
    }

    int pop() {
        int ret = data_[1];
        data_[1] = data_.back();
        data_.pop_back();
        int i = 1;
        while (i * 2 < data_.size()) {
            int c = i * 2;
            if (c + 1 < data_.size() && data_[c + 1] > data_[c]) {
                c = c + 1;
            }
            if (data_[i] < data_[c]) {
                swap(data_[i], data_[c]);
                i = c;
            } else {
                break;
            }
        }
        return ret;
    }

    bool empty() {
        return data_.size() == 1;
    }

private:
    vector<int> data_;
};

class Solution {
public:
     int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> projects;
        for (int i = 0; i < profits.size(); i++) {
            projects.push_back({capital[i], profits[i]});
        }
        sort(projects.begin(), projects.end());
        Heap heap;
        int i = 0;
        while (k--) {
            while (i < projects.size() && projects[i].first <= w) {
                heap.push(projects[i].second);
                i++;
            }
            if (heap.empty()) {
                break;
            }
            w += heap.pop();
        }
        return w;
     }
};