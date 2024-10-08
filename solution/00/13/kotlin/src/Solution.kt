class Solution {
    fun romanToInt(s: String): Int {
        val map = mapOf(
            'I' to 1,
            'V' to 5,
            'X' to 10,
            'L' to 50,
            'C' to 100,
            'D' to 500,
            'M' to 1000
        )
        var result = 0
        var prev = 0
        for (c in s.reversed()) {
            val value = map[c]!!
            if (value < prev) {
                result -= value
            } else {
                result += value
            }
            prev = value
        }
        return result
    }
}