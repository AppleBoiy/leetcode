from typing import List


class Solution:
    def fullJustify(self, words: List[str], max_width: int) -> List[str]:  # noqa
        result = []
        current_line = []
        current_width = 0

        for word in words:
            if current_width + len(current_line) + len(word) > max_width:
                for i in range(max_width - current_width):
                    current_line[i % (len(current_line) - 1 or 1)] += ' '
                result.append(''.join(current_line))
                current_line = []
                current_width = 0

            current_line.append(word)
            current_width += len(word)

        result.append(' '.join(current_line).ljust(max_width))

        return result


if __name__ == '__main__':
    _words = ["This", "is", "an", "example", "of", "text", "justification."]
    _max_width = 16
    _expected = [
        "This    is    an",
        "example  of text",
        "justification.  "
    ]

    solution = Solution()
    output = solution.fullJustify(_words, _max_width)
    assert output == _expected, f"{output} != {_expected}"
