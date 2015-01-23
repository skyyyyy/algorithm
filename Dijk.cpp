an example of Dijkstra and A*

Dijkstra's algorithm, conceived by computer scientist Edsger Dijkstra in 1956 and published in 1959,[1][2] 
is a graph search algorithm that solves the single-source shortest path problem for a graph with non-negative edge path costs, 
producing a shortest path tree. 
This algorithm is often used in routing and as a subroutine in other graph algorithms.

Dijkstra's original algorithm does not use a min-priority queue and runs in time O(|V|^2) (where |V| is the number of vertices). 
The idea of this algorithm is also given in (Leyzorek et al. 1957). T
he implementation based on a min-priority queue implemented by a Fibonacci heap and running in O(|E|+|V|\log|V|) 
(where |E| is the number of edges) is due to (Fredman & Tarjan 1984). 
This is asymptotically the fastest known single-source shortest-path algorithm for arbitrary directed graphs 
with unbounded non-negative weights.

Pseudocode[edit]
In the following algorithm, the code u ← vertex in Q with min dist[u], searches for the vertex u in the 
vertex set Q that has the least dist[u] value. length(u, v) returns the length of the edge joining 
(i.e. the distance between) the two neighbor-nodes u and v. 
The variable alt on line 19 is the length of the path from the root node to the neighbor node v
if it were to go through u. If this path is shorter than the current shortest path recorded for v, 
that current path is replaced with this alt path. The previous array is populated with a pointer to the "next-hop"
node on the source graph to get the shortest route to the source.

 1  function Dijkstra(Graph, source):
 2
 3      dist[source] ← 0                       // Distance from source to source
 4      prev[source] ← undefined               // Previous node in optimal path initialization
 5
 6      for each vertex v in Graph:  // Initialization
 7          if v ≠ source            // Where v has not yet been removed from Q (unvisited nodes)
 8              dist[v] ← infinity             // Unknown distance function from source to v
 9              prev[v] ← undefined            // Previous node in optimal path from source
10          end if 
11          add v to Q                     // All nodes initially in Q (unvisited nodes)
12      end for
13      
14      while Q is not empty:
15          u ← vertex in Q with min dist[u]  // Source node in first case
16          remove u from Q 
17          
18          for each neighbor v of u:           // where v has not yet been removed from Q.
19              alt ← dist[u] + length(u, v)
20              if alt < dist[v]:               // A shorter path to v has been found
21                  dist[v] ← alt 
22                  prev[v] ← u 
23              end if
24          end for
25      end while
26
27      return dist[], prev[]
28
29  end function
If we are only interested in a shortest path between vertices source and target, 
we can terminate the search after line 15 if u = target. 
Now we can read the shortest path from source to target by reverse iteration:

1  S ← empty sequence
2  u ← target
3  while prev[u] is defined:                 // Construct the shortest path with a stack S
4      insert u at the beginning of S          // Push the vertex onto the stack
5      u ← prev[u]                             // Traverse from target to source
6  end while


Using a priority queue[edit]
A min-priority queue is an abstract data structure that provides 3 basic operations : 
add_with_priority(), decrease_priority() and extract_min().
As mentioned earlier, using such a data structure can lead to faster computing times than using a basic queue.
Notably, Fibonacci heap (Fredman & Tarjan 1984) or Brodal queue offer optimal implementations for those 3 operations. 
As the algorithm is slightly different, we mention it here, in pseudo-code as well :

1  function Dijkstra(Graph, source):
2      dist[source] ← 0                      // Initialization
3      for each vertex v in Graph:           
4          if v ≠ source
5              dist[v] ← infinity            // Unknown distance from source to v
6              prev[v] ← undefined           // Predecessor of v
7          end if
8          Q.add_with_priority(v,dist[v])
9      end for 
10
11
12     while Q is not empty:               // The main loop
13         u ← Q.extract_min()               // Remove and return best vertex
14         mark u as scanned
15         for each neighbor v of u:
16             if v is not yet scanned:
17                 alt = dist[u] + length(u, v) 
18                 if alt < dist[v]
19                     dist[v] ← alt
20                     prev[v] ← u
21                     Q.decrease_priority(v,alt)
22                 end if
23             end if
24         end for
25     end while
26     return prev[]
Instead of filling the priority queue with all nodes in the initialization phase, 
it is also possible to initialize it to contain only source; then, inside the if alt < dist[v] block,
the node must be inserted if not already in the queue (instead of performing a decrease_priority operation).[3]:198

It should be noted that other data structures can be used to achieve even faster computing times in practice.[6]


