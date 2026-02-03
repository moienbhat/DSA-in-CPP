#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    bool detect(int src, vector<int> adj[], vector<int>& vis) {
        queue<pair<int,int>> q;
        q.push({src, -1});
        vis[src] = 1;

        while(!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for(int neighbor : adj[node]) {
                if(!vis[neighbor]) {
                    vis[neighbor] = 1;
                    q.push({neighbor, node});
                }
                else if(neighbor != parent) {
                    return true; // cycle detected
                }
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);

        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(detect(i, adj, vis)) return true;
            }
        }
        return false;
    }
};

int main() {
    int V = 4;
    vector<int> adj[V];

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    Solution obj;
    bool ans = obj.isCycle(V, adj);

    cout << (ans ? "1\n" : "0\n");

    return 0;
}
