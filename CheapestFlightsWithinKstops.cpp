#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution
{
public:
    // Method to find the cheapest flight within K stops using BFS
    int CheapestFLight(int n, vector<vector<int>> &flights,
                       int src, int dst, int K)
    {
        // Create the adjacency list to represent airports and flights as a graph
        vector<pair<int, int>> adj[n];
        for (auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});  // Add an edge from source to destination with the weight (cost)
        }

        // Create a queue to store the node, its distance from the source, and the number of stops
        queue<pair<int, pair<int, int>>> q;
        
        q.push({0, {src, 0}});  // Push the source node with 0 stops and 0 cost

        // Create a distance array to store the minimum cost to reach each node
        vector<int> dist(n, 1e9);
        dist[src] = 0;  // The distance from source to itself is 0

        // BFS traversal with a queue to process the nodes
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stops = it.first;  // Number of stops so far
            int node = it.second.first;  // Current node
            int cost = it.second.second;  // Cost to reach the current node

            // If the number of stops exceeds K, continue to the next iteration
            if (stops > K)
                continue;

            // Iterate over all the adjacent nodes (next destinations)
            for (auto iter : adj[node])
            {
                int adjNode = iter.first;  // Next destination node
                int edW = iter.second;  // Cost of the flight to the next destination

                // If a shorter path to the adjacent node is found, update the distance
                if (cost + edW < dist[adjNode] && stops <= K)
                {
                    dist[adjNode] = cost + edW;  // Update the distance
                    q.push({stops + 1, {adjNode, cost + edW}});  // Push the new node with updated stops and cost
                }
            }
        }

        // If destination node is unreachable, return -1
        if (dist[dst] == 1e9)
            return -1;

        return dist[dst];  // Return the minimum cost to reach the destination
    }
};

int main()
{
    // Driver Code.
    int n = 4, src = 0, dst = 3, K = 1;

    // Flight routes and their costs
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600},
    {2, 3, 200}};

    Solution obj;

    // Call the method to find the cheapest flight
    int ans = obj.CheapestFLight(n, flights, src, dst, K);

    // Output the result
    cout << ans << endl;

    return 0;
}
