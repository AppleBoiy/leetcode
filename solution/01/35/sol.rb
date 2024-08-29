# @param {Integer[]} ratings
# @return {Integer}
def candy(ratings)
    n = ratings.size
    return n if n < 2
    candies = Array.new(n, 1)
    (1...n).each do |i|
        if ratings[i] > ratings[i - 1]
        candies[i] = candies[i - 1] + 1
        end
    end
    (0...n - 1).reverse_each do |i|
        if ratings[i] > ratings[i + 1]
        candies[i] = [candies[i], candies[i + 1] + 1].max
        end
    end
    candies.sum
end