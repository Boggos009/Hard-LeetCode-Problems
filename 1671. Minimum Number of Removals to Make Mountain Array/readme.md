# Intuition

1-U need to solve LC300. Longest Increasing Subsequence and know its both solution (DP , binary search) , if u need any help 
* u can watch this video from neetcode for the DP solution`O(n²)`: https://www.youtube.com/watch?v=cjWnW0hdF1Y&source_ve_path=OTY3MTQ&embeds_referring_euri=https%3A%2F%2Fneetcode.io%2F 
* or this video from Techdose for the binary search solution`O(n log n)`:
https://www.youtube.com/watch?v=OIU8ZLC4qIQ

2-from the previous point u can solve this problem by consider every index `i` as the peak of a mountain. For a valid mountain:

- There must be an increasing subsequence ending at `i`.
- There must be a decreasing subsequence starting at `i`.

Let:

- `LIS[i]` = length of the longest increasing subsequence ending at `i`.
- `LDS[i]` = length of the longest decreasing subsequence starting at `i`.

If index `i` is chosen as the peak, then the length of the mountain formed through `i` is:

`LIS[i] + LDS[i] - 1`

We subtract `1` because the peak element is counted in both subsequences.

Therefore, we compute the maximum valid mountain length among all indices and remove the remaining elements.

# Approach

## Solution 1: Dynamic Programming (O(n²))

Let:

* `DPRIGHT[i]` = length of the Longest Increasing Subsequence ending at `i`.
* `DPLEFT[i]` = length of the Longest Decreasing Subsequence starting at `i`.

Compute `DPRIGHT` by checking all previous indices and extending increasing subsequences.

Compute `DPLEFT` by checking all later indices and extending decreasing subsequences.

Then try every index as the peak:

* A valid peak must have both values greater than `1`.
* Mountain length = `DPRIGHT[i] + DPLEFT[i] - 1`.

The minimum removals are:

`n - longestMountain`.

## Solution 2: Binary Search (O(n log n))

Maintain a temporary array `temp`:

* For each element, use `lower_bound` to find its position.
* The position gives the LIS length ending at that index.

Run this process:

1. Left to right to compute LIS ending at each position.
2. Right to left to compute LDS starting at each position.

Then compute the longest valid mountain exactly as in the DP solution.

# Complexity

## Solution 1

* Time complexity: `O(n²)`
* Space complexity: `O(n)`

## Solution 2

* Time complexity: `O(n log n)`
* Space complexity: `O(n)`