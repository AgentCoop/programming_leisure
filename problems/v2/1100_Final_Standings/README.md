# 1100. Final Standings
 * Time limit: 1.0 second
 * Memory limit: 16 MB
Old contest software uses bubble sort for generating final standings. But now, there are too many teams and that software works too slow. You are asked to write a program, which generates exactly the same final standings as old software, but fast.
## Input
The first line of input contains only integer 1 < N ≤ 150000 — number of teams. Each of the next N lines contains two integers 1 ≤ ID ≤ 107 and 0 ≤ M ≤ 100. ID — unique number of team, M — number of solved problems.
## Output
Output should contain N lines with two integers ID and M on each. Lines should be sorted by M in descending order as produced by bubble sort (see below).