# 1063. Domino Puzzle
# Time limit: 2.0 second
# Memory limit: 64 MB

# Background
# Dominoes, game played with small, rectangular blocks of wood or other material, each identified by a number of dots, or pips, on its face. The blocks usually are called bones, dominoes, or pieces and sometimes men, stones, or even cards. The face of each piece is divided, by a line or ridge, into two squares, each of which is marked as would be a pair of dice... The principle in nearly all modern dominoes games is to match one end of a piece to another that is identically or reciprocally numbered.
# ENCYCLOPÆDIA BRITANNICA
# Problem
# Consider an arbitrary set of domino pieces where each piece is marked with two digits from 1 to 6. Some sets can be completely laid out in a row matching one end of a piece to another that is identically numbered, while others cannot. For example, the set consisting of 5 pieces: (1, 5), (1, 6), (5, 5) and (2, 4) twice, cannot be laid out in a row. However, if we add (2, 5) piece to the above set we could lay out the resulting set in the following row:
# Problem illustration
# However, we are interested in a row having the smallest sum of digits on its pieces. In our example, instead of the piece (2, 5) with a sum of 7, we could add two pieces (1, 2) with a total sum of 6 to lay out the following row:
# Problem illustration
# Your task is to write a program that for a given domino set will find an additional (possibly empty) set with the smallest possible sum of digits, so that a row could be laid out with both sets combined.

# Input
# The first line contains a single integer N representing the total number of pieces in the domino set (2 ≤ N ≤ 100). The following N lines describe pieces. Each piece is represented on a separate line in a form of two digits from 1 to 6 separated by a space. The digits of a piece can be written in any order.

# Output
# On the first line write the smallest sum of digits of the additional set or 0 if that set is empty. On the second line write the total number of pieces in the additional set or 0 if that set is empty. Then write the pieces of the additional set in the same format as in input.
# If there are a number of additional sets with the same smallest sum of digits exist then write any one of them.

from itertools import combinations

def find_min_sum_set(domino_set):
    # Generate all possible combinations of additional set
    additional_sets = [[]]
    for i in range(1, len(domino_set)+1):
        additional_sets += list(combinations(domino_set, i))

    # Compute the sum of each combined set and select the one with the smallest sum
    min_sum = float('inf')
    min_sum_set = []
    for additional_set in additional_sets:
        combined_set = domino_set + list(additional_set)
        if is_valid(combined_set):
            total_sum = sum(sum(pair) for pair in combined_set)
            if total_sum < min_sum:
                min_sum = total_sum
                min_sum_set = additional_set

    return min_sum_set

def is_valid(domino_set):
    # Check if the domino set can be laid out in a row
    count = {}
    for pair in domino_set:
        for num in pair:
            count[num] = count.get(num, 0) + 1
    for value in count.values():
        if value % 2 != 0:
            return False
    return True

  
domino_set = [(1, 5), (6, 1), (5, 5), (2, 4), (2, 4)]

min_sum_set = find_min_sum_set(domino_set)
print(min_sum_set)
print("Done")