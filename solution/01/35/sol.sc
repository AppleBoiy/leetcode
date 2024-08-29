object Solution {
    def candy(ratings: Array[Int]): Int = {
        val n = ratings.length
        val left = Array.fill(n)(1)
        val right = Array.fill(n)(1)
        for (i <- 1 until n) {
            if (ratings(i) > ratings(i - 1)) {
                left(i) = left(i - 1) + 1
            }
        }
        for (i <- n - 2 to 0 by -1) {
            if (ratings(i) > ratings(i + 1)) {
                right(i) = right(i + 1) + 1
            }
        }
        var ans = 0
        for (i <- 0 until n) {
            ans += Math.max(left(i), right(i))
        }
        ans
    }
}