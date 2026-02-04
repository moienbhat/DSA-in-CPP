#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<set>

using namespace std;

class Solution {
private:
    int timer = 1; // Global timer to assign discovery times

    // Depth-First Search (DFS) to find bridges
    void dfs(int node, int parent, vector<int> &vis,
             vector<int> adj[], int tin[], int low[],
             vector<vector<int>> &bridges) {
        vis[node] = 1;                 // Mark current node as visited
        tin[node] = low[node] = timer; // Set discovery time and low-link value
        timer++;

        for (auto it : adj[node]) {    // Explore all adjacent nodes
            if (it == parent) continue; // Skip the edge to parent

            if (vis[it] == 0) {
                // If neighbor is unvisited, recurse
                dfs(it, node, vis, adj, tin, low, bridges);

                // Update low-link value of current node
                low[node] = min(low[node], low[it]);

                // Check if the edge is a bridge
                if (low[it] > tin[node]) {
                    bridges.push_back({it, node});
                }
            } else {
                // Back edge: update low-link value
                low[node] = min(low[node], low[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n,
        vector<vector<int>>& connections) {

        // Step 1: Build adjacency list
        vector<int> adj[n];
        for (auto it : connections) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Step 2: Initialize helper arrays
        vector<int> vis(n, 0);
        int tin[n]; // Discovery time
        int low[n]; // Lowest reachable time
        vector<vector<int>> bridges;

        // Step 3: Run DFS (assuming graph is connected)
        dfs(0, -1, vis, adj, tin, low, bridges);

        return bridges;
    }
};

int main() {
    int n = 4;
    vector<vector<int>> connections = {
        {0, 1}, {1, 2}, {2, 0}, {1, 3}
    };

    Solution obj;
    vector<vector<int>> bridges = obj.criticalConnections(n, connections);

    cout << "Critical Connections (Bridges): ";
    for (auto it : bridges) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;

    return 0;
}