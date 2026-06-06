# Intuition

For every position `i`, we want to know the minimum number of extra characters in the suffix `s[i...]`.

At index `i`, we have two choices:

1. Treat `s[i]` as an extra character.
2. Match a dictionary word starting at `i`.

If a dictionary word ends at index `j`, then all characters in `s[i...j]` are covered and contribute `0` extra characters, so we continue from `j + 1`.

To efficiently find all dictionary words starting at a given position, we store the dictionary in a Trie.

# Approach

Let `dp[i]` be the minimum number of extra characters in the suffix `s[i...]`.

We process the string from right to left.

For every index `i`:

* First, assume `s[i]` is an extra character:

```cpp
dp[i] = 1 + dp[i + 1];
```

* Then traverse the Trie starting from `s[i]`.
* Whenever we reach a Trie node marked as a complete word ending at position `j`, we can use that word and update:

```cpp
dp[i] = min(dp[i], dp[j + 1]);
```

The Trie allows us to quickly enumerate all dictionary words that start at index `i` without checking every word in the dictionary.

# Complexity

* Time complexity: **O(n × L)**

Where:

* `n` is the length of `s`
* `L` is the maximum length of a dictionary word

For each position, the Trie traversal can advance at most `L` characters before stopping.

* Space complexity: **O(n + D)**

Where:

* `n` is the size of the DP array
* `D` is the total number of characters stored in the Trie
