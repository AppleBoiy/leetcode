from random import choice

"""
RandomizedSet randomizedSet = new RandomizedSet();
randomizedSet.insert(1); // Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomizedSet.remove(2); // Returns false as 2 does not exist in the set.
randomizedSet.insert(2); // Inserts 2 to the set, returns true. Set now contains [1,2].
randomizedSet.getRandom(); // getRandom() should return either 1 or 2 randomly.
randomizedSet.remove(1); // Removes 1 from the set, returns true. Set now contains [2].
randomizedSet.insert(2); // 2 was already in the set, so return false.
randomizedSet.getRandom(); // Since 2 is the only number in the set, getRandom() will always return 2.
"""


class RandomizedSet:

    def __init__(self):
        self.data = set()

    def insert(self, val: int) -> bool:
        if val in self.data:
            return False
        self.data.add(val)
        return True

    def remove(self, val: int) -> bool:
        if val in self.data:
            self.data.remove(val)
            return True
        return False

    def getRandom(self) -> int:
        return choice(list(self.data))


if __name__ == '__main__':
    randomizedSet = RandomizedSet()
    assert randomizedSet.insert(1) is True
    assert randomizedSet.remove(2) is False
    assert randomizedSet.insert(2) is True
    assert randomizedSet.getRandom() in [1, 2]
    assert randomizedSet.remove(1) is True
    assert randomizedSet.insert(2) is False
    assert randomizedSet.getRandom() == 2
    print('Passed!')
