from typing import List


def is_palindrome(s):
    return s == s[::-1]


def array_is_equal(a, b):
    return sorted(a) == sorted(b)


class SolutionPlaceholder:
    """336. Palindrome Pairs"""

    def sol1(self, words: List[str]) -> List[List[int]]:  # noqa
        result = []
        indices = {word: i for i, word in enumerate(words)}
        for i, word in enumerate(words):
            for j in range(len(word) + 1):
                left, right = word[:j], word[j:]
                if left == left[::-1] and right[::-1] != word and right[::-1] in indices:
                    result.append([indices[right[::-1]], i])
                if j != len(word) and right == right[::-1] and left[::-1] != word and left[::-1] in indices:
                    result.append([i, indices[left[::-1]]])
        return result

    def sol2(self, words: List[str]) -> List[List[int]]:  # noqa
        """
        Time complexity: O(n * k^2)
        Space complexity: O(n)

        :exception: Time Limit Exceeded at 135/136
        """
        result = []
        n = len(words)
        for i in range(n):
            for j in range(i + 1, n):
                left, right = words[i], words[j]
                word1, word2 = left + right, right + left
                if is_palindrome(word1):
                    result.append([i, j])
                if is_palindrome(word2):
                    result.append([j, i])
        return result

    def sol3(self, words: List[str]) -> List[List[int]]:  # noqa

        indices = {word: i for i, word in enumerate(words)}
        result = []

        for i, word in enumerate(words):
            n = len(word)
            for j in range(n + 1):
                left, right = word[:j], word[j:]

                if is_palindrome(left):
                    reversed_right = right[::-1]
                    if reversed_right in indices and indices[reversed_right] != i:
                        result.append([indices[reversed_right], i])

                    reversed_left = left[::-1]
                    if reversed_left in indices and indices[reversed_left] != i:
                        result.append([i, indices[reversed_left]])

        return result


class Solution(SolutionPlaceholder):
    def palindromePairs(self, words: List[str]) -> List[List[int]]:  # noqa
        return self.sol1(words)


if __name__ == '__main__':
    _words = ["abcd", "dcba", "lls", "s", "sssll"]
    _h = [[0, 1], [1, 0], [3, 2], [2, 4]]
    _s = Solution()
    _a = _s.palindromePairs(_words)
    assert array_is_equal(_a, _h), f'Error: Expected {_h}, but got {_a}'
