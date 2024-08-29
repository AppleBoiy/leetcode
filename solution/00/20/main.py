if __name__ == '__main__':
    from sol import Solution

    solver = Solution().isValid

    s = "()"
    expected = True
    assert (result := solver(s)) == expected, f"unexpected {result=}"

    s = "()[]{}"
    expected = True
    assert (result := solver(s)) == expected, f"unexpected {result=}"

    s = "(]"
    expected = False
    assert (result := solver(s)) == expected, f"unexpected {result=}"

    s = "([)]"
    expected = False
    assert (result := solver(s)) == expected, f"unexpected {result=}"
