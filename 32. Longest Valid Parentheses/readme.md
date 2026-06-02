# Intuition
We can use DP where dp[i] represents the length of the longest valid parentheses substring that ends at index i.

# Approach
We update dp[i] only when s[i] == ')'.

If the previous character is '(', then we found a valid "()" pair:
dp[i] = dp[i-2] + 2

Otherwise, it might be a nested group like "(())".
Let prev = dp[i-1]. This tells us the length of the valid substring ending at i-1.
We jump back to check the character that may match the current ')':
j = i - prev - 1

If j >= 0 and s[j] == '(', then we extend the valid substring:
dp[i] = dp[i-1] + 2 + dp[j-1]

# Complexity
- Time complexity: O(n)
- Space complexity: O(n)
