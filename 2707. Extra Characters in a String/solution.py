class TrieNode:
    def __init__(self):
        self.mp = {}
        self.is_leaf = False


class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, s):
        cur = self.root

        for c in s:
            if c not in cur.mp:
                cur.mp[c] = TrieNode()

            cur = cur.mp[c]

        cur.is_leaf = True


class Solution:
    def minExtraChar(self, s: str, dictionary: list[str]) -> int:
        trie = Trie()

        for word in dictionary:
            trie.insert(word)

        n = len(s)
        dp = [0] * (n + 1)

        for i in range(n - 1, -1, -1):
            dp[i] = 1 + dp[i + 1]

            cur = trie.root

            for j in range(i, n):
                if s[j] not in cur.mp:
                    break

                cur = cur.mp[s[j]]

                if cur.is_leaf:
                    dp[i] = min(dp[i], dp[j + 1])

        return dp[0]