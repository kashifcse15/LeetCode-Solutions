```cpp
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        // Step 1: Build adjacency list
        for (auto edge : prerequisites) {
            int u = edge[1];
            int v = edge[0];

            adj[u].push_back(v);
        }

        // Step 2: Calculate indegree separately
        vector<int> indegree(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            for (int neighbour : adj[i]) {
                indegree[neighbour]++;
            }
        }

        // Step 3: Push nodes with indegree 0
        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Step 4: Kahn's Algorithm
        int count = 0;

        
        return count == numCourses;
    }
};
```
