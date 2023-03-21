# 1099. Work Scheduling
# Time limit: 0.5 second
# Memory limit: 64 MB

# There is a certain amount of night guards that are available to protect the local junkyard from possible junk robberies. These guards need to be scheduled in pairs so that each pair guards in a different night. The junkyard CEO ordered you to write a program which given the guards characteristics determines the maximum amount of scheduled guards (the rest will be fired). Please note that each guard can be scheduled with only one of his colleagues and no guard can work alone.

# Input
# The first line of the input contains one number N ≤ 222 which is a number of night guards. Unlimited number of lines consisting of unordered pairs (i, j) follow, each such pair means that guard #i and guard #j can work together, because it is possible to find uniforms that suit both of them (The junkyard uses different parts of uniforms for different guards i.e. helmets, pants, jackets. It is impossible to put small helmet on a guard with a big head or big shoes on guard with small feet). The input ends with Eof.

# Output
# You should output one possible optimal assignment. On the first line of the output write the even number C, the amount of scheduled guards. Then output C/2 lines, each containing 2 integers (i, j) that denote that i and j will work together.
----------------------------------------------
# One approach to solve this problem is to use the Maximum Cardinality Bipartite Matching algorithm. The idea is to model the problem as a bipartite graph, where the left side represents the set of guards, and the right side represents the set of nights. An edge between a guard and a night means that the guard can work on that night.
# The algorithm starts with an empty matching, and iteratively tries to find augmenting paths in the bipartite graph. An augmenting path is a path that starts and ends with free vertices (i.e., vertices that are not in the matching) and alternates between edges in the matching and edges not in the matching. If an augmenting path is found, the matching is updated by adding the edges of the augmenting path and removing the edges that were previously in the matching.
# The algorithm terminates when no augmenting path can be found, and the size of the matching is the maximum number of guards that can be scheduled.

from collections import defaultdict

def maximum_matching(n, pairs):
    # Create bipartite graph
    graph = defaultdict(list)
    for i, j in pairs:
        graph[i].append(j)
        graph[j].append(i)

    # Initialize matching
    matching = {}
    for i in range(n):
        matching[i] = None

    # Find augmenting paths
    while True:
        free = [i for i in range(n) if matching[i] is None]
        if not free:
            break

        visited = defaultdict(bool)
        parent = {}
        for i in free:
            queue = [i]
            visited[i] = True
            parent[i] = None

            while queue:
                node = queue.pop(0)
                for neighbor in graph[node]:
                    if not visited[neighbor]:
                        visited[neighbor] = True
                        parent[neighbor] = node
                        if matching[neighbor] is None:
                            # Augmenting path found
                            while node is not None:
                                matching[node] = neighbor
                                matching[neighbor] = node
                                node = parent[node]
                            break
                        else:
                            queue.append(matching[neighbor])
                if matching[i] is not None:
                    # Augmenting path found
                    break

    # Count number of scheduled guards
    count = sum(1 for i in range(n) if matching[i] is not None)

    return count