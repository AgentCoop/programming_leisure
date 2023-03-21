# 1005. Stone Pile
# Time limit: 1.0 second
# Memory limit: 64 MB
# You have a number of stones with known weights w1, …, wn. Write a program that will rearrange the stones into two piles such that weight difference between the piles is minimal.

# Input
# Input contains the number of stones n (1 ≤ n ≤ 20) and weights of the stones w1, …, wn (integers, 1 ≤ wi ≤ 100000) delimited by white spaces.

# Output
# Your program should output a number representing the minimal possible weight difference between stone piles.
# -------------------------------------------------------------------------------------------------
# To solve this problem, we can use dynamic programming approach. Let's define a two-dimensional boolean array DP, where DP[i][j] is true if it's possible to obtain a sum of j using the first i stones.

# We can start by initializing DP[0][0] to true, since we can obtain a sum of zero using zero stones. Then, for each stone i, we update DP[i][j] as follows:

# If DP[i-1][j] is true, then DP[i][j] is also true. This means that we can obtain a sum of j using only the first i-1 stones.
# If DP[i-1][j-w[i]] is true, then DP[i][j] is also true. This means that we can obtain a sum of j by adding the i-th stone to the sum of j-w[i] using the first i-1 stones.
# Once we have filled in the DP array, we can iterate over the possible sums j from sum/2 to 0 (where sum is the total weight of all stones) and find the largest j such that DP[n][j] is true. This will give us the weight of one pile, and the weight of the other pile is simply sum-j.

def minimize_weight_difference(weights):
    n = len(weights)
    total_weight = sum(weights)
    DP = [[False]*(total_weight//2+1) for _ in range(n+1)]
    DP[0][0] = True
    for i in range(1, n+1):
        for j in range(total_weight//2+1):
            DP[i][j] = DP[i-1][j]
            if j >= weights[i-1]:
                DP[i][j] |= DP[i-1][j-weights[i-1]]
    for j in range(total_weight//2, -1, -1):
        if DP[n][j]:
            return total_weight - 2*j