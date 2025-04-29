
// Overview
// The Bellman-Ford Algorithm is a single-source shortest path algorithm designed for graphs that may contain negative edge weights. Unlike Dijkstra's algorithm, Bellman-Ford can handle graphs with negative weight edges and is capable of detecting negative weight cycles





// How Bellman-Ford Detects Negative Cycles
// 1. Relax edges for V-1 iterations: This computes shortest paths assuming no negative cycles.

// 2. Check edges one final time: If any edge can still be relaxed (i.e., a shorter path is found), a negative cycle exists.
// A negative cycle allows infinite "shortening" of paths, violating the shortest path definition.

