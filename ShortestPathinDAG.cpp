#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
private:
    // DFS to generate Topological Order
    void topoSort(int node, vector<pair<int,int>> adj[], vector<int> &vis, stack<int> &st) {
        vis[node] = 1;

        for (auto it : adj[node]) {
            int v = it.first;
            if (!vis[v]) {
                topoSort(v, adj, vis, st);
            }
        }
        st.push(node);
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges) {

        // Step 1: Build adjacency list
        vector<pair<int,int>> adj[N];

        for (int i = 0; i < M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            adj[u].push_back({v, wt});
        }

        // Step 2: Topological Sort
        vector<int> vis(N, 0);
        stack<int> st;

        for (int i = 0; i < N; i++) {
            if (!vis[i]) {
                topoSort(i, adj, vis, st);
            }
        }

        // Step 3: Initialize distance array
        vector<int> dist(N, 1e9);
        dist[0] = 0;

        // Step 4: Process nodes in Topo Order
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (dist[node] != 1e9) {
                for (auto it : adj[node]) {
                    int v = it.first;
                    int wt = it.second;

                    if (dist[node] + wt < dist[v]) {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }

        // Step 5: Convert unreachable nodes to -1
        for (int i = 0; i < N; i++) {
            if (dist[i] == 1e9)
                dist[i] = -1;
        }

        return dist;
    }
};


int main() {
    int N = 6, M = 7;

    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 4, 1},
        {4, 5, 4},
        {4, 2, 2},
        {1, 2, 3},
        {2, 3, 6},
        {5, 3, 1}
    };

    Solution obj;
    vector<int> ans = obj.shortestPath(N, M, edges);

    for (int x : ans)
        cout << x << " ";

    return 0;
}
