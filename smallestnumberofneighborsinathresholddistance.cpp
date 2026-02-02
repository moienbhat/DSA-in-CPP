#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    // Method to find the city with the least reachable cities within the threshold distance
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        
        // Initialize the distance matrix with a large value (INT_MAX)
        vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
        
        // Set the distance for each edge
        for (auto it : edges) {
            dist[it[0]][it[1]] = it[2];  // Set the distance from city1 to city2
            dist[it[1]][it[0]] = it[2];  // Set the distance from city2 to city1
        }
        
        // Set the diagonal to 0, as the distance from a city to itself is 0
        for (int i = 0; i < n; i++) dist[i][i] = 0;

        // Apply Floyd-Warshall Algorithm to find the shortest paths between all pairs of cities
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    // Update the distance if a shorter path is found
                    if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
                        continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        // Initialize variables to track the city with the least reachable cities
        int cntCity = n;
        int cityNo = -1;

        // Check each city and count the number of cities within the threshold distance
        for (int city = 0; city < n; city++) {
            int cnt = 0;
            for (int adjCity = 0; adjCity < n; adjCity++) {
                // If the distance to the adjacent city is within the threshold, increment count
                if (dist[city][adjCity] <= distanceThreshold)
                    cnt++;
            }

            // Update the city with the least number of reachable cities
            if (cnt <= cntCity) {
                cntCity = cnt;
                cityNo = city;
            }
        }
        return cityNo;
    }
};

int main() {
    // Input data
    int n = 4;
    int m = 4;
    vector<vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
    int distanceThreshold = 4;

    // Create an object of the Solution class
    Solution obj;

    // Find the city with the least reachable cities within the threshold distance
    int cityNo = obj.findCity(n, m, edges, distanceThreshold);

    // Output the result
    cout << "The answer is node: " << cityNo << endl;

    return 0;
}