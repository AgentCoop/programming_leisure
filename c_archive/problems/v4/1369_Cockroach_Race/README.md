# 1369. Cockroach Race
 * Time limit: 2.0 second
 * Memory limit: 64 MB

At last, the spring came. Buds swell on the trees, the snow has almost thawn out. More and more often you can hear birds' sonorous twittering from the outside. Less and less students you can see at the USU math-mech department. Even the cockroaches, usual inhabitants of the hostels, show up very rarely.
What's the connection between these phenomena, you may ask.

The answer is the Day of Mathematician and Mechanician celebration, which will begin really soon. At the same time, the traditional cockroach race will take place in the USU. That's what the students are occupied with now—they are training their pets. Everyone wants his pet to become the prize-winner and to receive the proud name of "Magaz".

The race rules are somewhat unusual. Every round, some kind of sweets are placed in N points of the racing area. Together with sweets, M cockroaches are released. N cockroaches that reach these little delights of cockroaches' life, will make it to the next round.

During the race all spectators have an unique opportunity to place bets and to win a lot of money. But the totalizator organizers are puzzled, they cannot understand how to calculate the probabilities of cockroaches' victories quickly and without mistakes. This is absolutely required to make the maximum profit out of their enterprise. Math-mech is rather big department and everyone here wants to participate.

You are to determine, for each of N pieces of sweet, which of the cockroaches is closest to that piece. This will help to determine the race leaders.
## Input
The first line contains an integer M (1 ≤ M ≤ 100000). M lines follow, containing coordinates of the cockroaches at the present moment. (M + 2)nd line contains an integer N (0 ≤ N ≤ 10000). N following lines contain coordinates of sweet pieces. All coordinates are floating point numbers (−10000.0 ≤ x, y ≤ 10000.0). The distance between any two cockroaches is not less than 10−3. Also the distance between any two sweets is not less than 10−3.
## Output
For each piece of "Cockroach Sweets" you should output all cockroaches closest to that piece in ascending order of their numbers separated by spaces.