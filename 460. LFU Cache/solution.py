from collections import defaultdict


class Node:
    def __init__(self, key: int, val: int):
        self.key = key
        self.val = val
        self.prev = None
        self.next = None


class LRUCacheList:
    def __init__(self):
        self.LRU = None
        self.MRU = None

    def removeNode(self, node):
        if node.prev:
            node.prev.next = node.next
        else:
            self.LRU = node.next

        if node.next:
            node.next.prev = node.prev
        else:
            self.MRU = node.prev

    def insertToMRU(self, node):
        node.next = None
        node.prev = self.MRU

        if self.MRU:
            self.MRU.next = node

        self.MRU = node

        if self.LRU is None:
            self.LRU = node


class LFUCache:

    def __init__(self, capacity: int):
        self.cap = capacity
        self.mp = {}
        self.freqmp = defaultdict(int)
        self.cachemp = defaultdict(LRUCacheList)
        self.minCount = 1

    def get(self, key: int) -> int:
        if key not in self.mp:
            return -1

        node = self.mp[key]

        self.cachemp[self.freqmp[key]].removeNode(node)
        self.freqmp[key] += 1
        self.cachemp[self.freqmp[key]].insertToMRU(node)

        if self.cachemp[self.minCount].LRU is None:
            self.minCount += 1

        return node.val

    def put(self, key: int, value: int) -> None:
        if self.cap == 0:
            return

        if key in self.mp:
            node = self.mp[key]
            node.val = value

            self.cachemp[self.freqmp[key]].removeNode(node)

            if self.cachemp[self.minCount].LRU is None:
                self.minCount += 1

            self.freqmp[key] += 1
            self.cachemp[self.freqmp[key]].insertToMRU(node)

        else:
            if len(self.mp) == self.cap:
                deleted = self.cachemp[self.minCount].LRU

                del self.freqmp[deleted.key]
                self.cachemp[self.minCount].removeNode(deleted)
                del self.mp[deleted.key]

            node = Node(key, value)

            self.mp[key] = node
            self.freqmp[key] = 1

            self.cachemp[1].insertToMRU(node)
            self.minCount = 1