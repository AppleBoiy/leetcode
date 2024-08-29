import unittest


class Solution:
    def solution_1(self, s: str) -> int:  # noqa
        _max = 0
        _start = 0
        _dict = {}
        for _idx, _char in enumerate(s):
            if _char in _dict:
                _start = max(_start, _dict[_char] + 1)
            _dict[_char] = _idx
            _max = max(_max, _idx - _start + 1)
        return _max

    def solution_2(self, s: str) -> int:  # noqa
        n = len(s)
        if n == 0:
            return 0

        most = curr = 0
        seen = set()
        for i in range(n):
            for j in range(i, n):
                if s[j] not in seen:
                    seen.add(s[j])
                    curr += 1
                else:
                    break
            most = max(most, curr)
            seen.clear()
            curr = 0
        return most

    def lengthOfLongestSubstring(self, s: str) -> int:
        return self.solution_2(s)


class LTest(unittest.TestCase):
    cases = {
        "case_1": ("abcabcbb", 3),
        "case_2": ("bbbbb", 1),
        "case_3": ("pwwkew", 3),
        "case_4": ("", 0),
        "case_5": (" ", 1),
        "case_6": ("au", 2),
        "case_7": ("dvdf", 3),
        "case_8": ("tmmzuxt", 5),
        "case_9": ("abba", 2),
        "case_10": ("aab", 2),
        "case_11": ("cdd", 2),
        "case_12": ("abcb", 3),
    }

    def test_solution_1(self):
        for key in self.cases:
            _input, _expected = self.cases[key]
            self.assertEqual(Solution().solution_1(_input), _expected)

    def test_solution_2(self):
        for key in self.cases:
            _input, _expected = self.cases[key]
            self.assertEqual(Solution().solution_2(_input), _expected)


if __name__ == '__main__':
    unittest.main()
