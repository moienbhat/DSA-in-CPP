#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    // Function to verify if all courses can be finished
    bool canFinish(int numCourses, 
                   vector<vector<int>>& prerequisites) {
        // Build adjacency list
        vector<vector<int>> adj(numCourses);
        // Build in-degree array
        vector<int> inDegree(numCourses, 0);

        // Fill adjacency and in-degree
        for (auto& pre : prerequisites) {
            int a = pre[0], b = pre[1];
            adj[b].push_back(a);
            inDegree[a]++;
        }

        // Initialize queue with zero in-degree nodes
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        // Count processed nodes
        int count = 0;

        // Process queue
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            // Reduce in-degree of neighbors
            for (int nei : adj[node]) {
                inDegree[nei]--;
                if (inDegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        // Return true if all nodes processed
        return count == numCourses;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
    int numCourses = 2;
    cout << (sol.canFinish(numCourses, prerequisites) 
             ? "true" : "false");
    return 0;
}