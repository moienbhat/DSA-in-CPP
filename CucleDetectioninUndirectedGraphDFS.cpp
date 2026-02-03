#include<iostream>
#include<vector>


using namespace std;

bool dfs(int node, int parent, vector<int> adj[], vector<int> &visited) {
    visited[node] = 1;

    for( int neighbour : adj[node]) {
        if(!visited[neighbour]) {
            if(dfs(neighbour, node, adj, visited)) return true;
        }

        else if(neighbour != parent){
            return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    vector<int> visited(V, 0);

    for(int i=0; i<V; i++) {
        if(!visited[i]) {
            if(dfs(i, -1, adj, visited)) return true;
        }
    }
    return false;
}


int main() {
    // Example: Graph with 5 nodes and a cycle
    int V = 5;
    vector<int> adj[V];

    // Add edges
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(3);
    adj[4].push_back(1); 

    if (isCycle(V, adj))
        cout << "Cycle detected\n";
    else
        cout << "No cycle found\n";

}

