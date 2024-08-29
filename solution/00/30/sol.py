from typing import List


class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:  # noqa
        if not s or not words:
            return []

        word_len = len(words[0])
        word_count = len(words)
        word_map = {}

        for word in words:
            word_map[word] = word_map.get(word, 0) + 1

        result = []
        for i in range(word_len):
            left = i
            right = i
            current_map = {}
            count = 0

            while right + word_len <= len(s):
                word = s[right:right + word_len]
                right += word_len

                if word not in word_map:
                    left = right
                    current_map.clear()
                    count = 0
                else:
                    current_map[word] = current_map.get(word, 0) + 1
                    count += 1

                    while current_map[word] > word_map[word]:
                        current_map[s[left:left + word_len]] -= 1
                        left += word_len
                        count -= 1

                    if count == word_count:
                        result.append(left)

        return result


if __name__ == '__main__':
    _s = "barfoothefoobarman"
    _words = ["foo", "bar"]
    _expected = [0, 9]

    solution = Solution()
    output = solution.findSubstring(_s, _words)
    assert output == _expected, f"{output} != {_expected}"
