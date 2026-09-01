
class Solution {
public:
    vector<vector<int>> primMST(int V, vector<vector<int>> adj[]) {

        // {weight, node, parent}
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        vector<int> vis(V, 0);
        vector<vector<int>> mst;

        pq.push({0, 0, -1});

        while (!pq.empty()) {

            auto it = pq.top();
            pq.pop();

            int wt = it[0];
            int node = it[1];
            int parent = it[2];

            if (vis[node])
                continue;

            vis[node] = 1;

            if (parent != -1)
                mst.push_back({parent, node, wt});

            for (auto &it : adj[node]) {

                int adjNode = it[0];
                int edgeWt = it[1];

                if (!vis[adjNode]) {
                    pq.push({edgeWt, adjNode, node});
                }
            }
        }

        return mst;
    }
};
