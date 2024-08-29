if __name__ == '__main__':
    from sol_dynamic import Solution

    solver = Solution().longestPalindrome

    test = {
        "babad": "bab",
        "cbbd": "bb",
        "a": "a",
        "bb": "bb",
        "bbb": "bbb",
        "ac": "a"
    }
    for s, expected in test.items():
        assert (result := solver(s)) == expected, f"unexpected {expected} != {result=}"

    # assert (result := "bbb") == (expected := solver("bbb")), f"unexpected {expected=} != {result=}"
