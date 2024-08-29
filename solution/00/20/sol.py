class Solution:
    def isValid(self, s: str) -> bool:  # noqa
        op = {
            "{": "}",
            "[": "]",
            "(": ")"
        }
        q = []
        for char in s:
            if char in op:
                q.append(char)
            else:
                if not q:
                    return False
                openp = q.pop()
                if char != op[openp]:
                    return False
        return not q
