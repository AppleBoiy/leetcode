fun main() {
    val solution = Solution()

    val testCases = listOf(
        "III" to 3,
        "IV" to 4,
        "IX" to 9,
        "LVIII" to 58,
        "MCMXCIV" to 1994
    )

    for ((input, expected) in testCases) {
        val result = solution.romanToInt(input)
        println("romanToInt(\"$input\") = $result; Expected = $expected")
        assert(result == expected) { "Test failed for input $input" }
    }
}
