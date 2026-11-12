/*M-Coloring Problem
You are given an undirected graph consisting of V vertices and E edges represented by a list edges[][], along with an integer m. 
Your task is to find if it is possible to color the graph using at most m different colors such that no two adjacent vertices share 
the same color. 

Note: The graph is indexed with 0-based indexing.

Examples:

Input: V = 4, edges[][] = [[0, 1], [1, 3], [2, 3], [3, 0], [0, 2]], m = 3
Output: true
Explanation: It is possible to color the given graph using 3 colors, for example, one of the possible ways vertices can be colored as follows:

Vertex 0: Color 1
Vertex 1: Color 2
Vertex 2: Color 2
Vertex 3: Color 3
Input: V = 3, edges[][] = [[0, 1], [1, 2], [0, 2]], m = 2
Output: false
Explanation: It is not possible to color the given graph using only 2 colors because vertices 0, 1, and 2 form a triangle.
Constraints:
1 ≤ V ≤ 10
1 ≤ E = edges.size() ≤ (V*(V-1))/2
0 ≤ edges[i][j] ≤ V-1
1 ≤ m ≤ V
*/

#include <bits/stdc++.h>
using namespace std;

bool isSafe(int node, int color, vector<int>& colors,
            vector<vector<int>>& adj) {

    for (int neighbor : adj[node]) {
        if (colors[neighbor] == color)
            return false;
    }

    return true;
}

bool solve(int node, int v, int m, vector<int>& colors,
           vector<vector<int>>& adj) {

    // All vertices are colored
    if (node == v)
        return true;

    // Try colors 1 to m
    for (int color = 1; color <= m; color++) {

        if (isSafe(node, color, colors, adj)) {

            // Assign color
            colors[node] = color;

            // Recursively color remaining vertices
            if (solve(node + 1, v, m, colors, adj))
                return true;

            // Backtrack
            colors[node] = 0;
        }
    }

    return false;
}

bool graphColoring(int v, vector<vector<int>>& edges, int m) {

    // Adjacency list
    vector<vector<int>> adj(v);

    for (auto& edge : edges) {
        int u = edge[0];
        int w = edge[1];

        adj[u].push_back(w);
        adj[w].push_back(u);
    }

    // 0 means no color assigned
    vector<int> colors(v, 0);

    return solve(0, v, m, colors, adj);
}

int main() {

    int v, e, m;

    cout << "Enter number of vertices: ";
    cin >> v;

    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<int>> edges(e, vector<int>(2));

    cout << "Enter the edges:\n";

    for (int i = 0; i < e; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    cout << "Enter number of colors: ";
    cin >> m;

    if (graphColoring(v, edges, m))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}