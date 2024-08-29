class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i = 0;
        while (i < flowerbed.size() && n > 0) {
            if (flowerbed[i] == 0) {
                int prev = i == 0 ? 0 : flowerbed[i - 1];
                int next = i == flowerbed.size() - 1 ? 0 : flowerbed[i + 1];
                if (prev == 0 && next == 0) {
                    flowerbed[i] = 1;
                    n--;
                }
            }
            i++;
        }
        return n == 0;
    }
};