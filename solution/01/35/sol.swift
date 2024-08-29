class Solution {
    func candy(_ ratings: [Int]) -> Int {
        var candies = Array(repeating: 1, count: ratings.count)
        for i in 1..<ratings.count {
            if ratings[i] > ratings[i - 1] {
                candies[i] = candies[i - 1] + 1
            }
        }
        for i in (0..<ratings.count - 1).reversed() {
            if ratings[i] > ratings[i + 1] {
                candies[i] = max(candies[i], candies[i + 1] + 1)
            }
        }
        return candies.reduce(0, +)
    }
}