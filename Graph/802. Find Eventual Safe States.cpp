class Solution { 
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>revGraph(n);
        vector<int>outDegree(n);
        vector<int>ans;

        for(int i=0;i<n;i++){
            outDegree[i]=graph[i].size();
            for(int neigh:graph[i]){
                revGraph[neigh].push_back(i);
            }
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(outDegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);

            for(int parent:revGraph[node]){
                outDegree[parent]--;

                if(outDegree[parent]==0){
                    q.push(parent);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;

    }
};


(BY CYCLE DETECTION)
class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph,
             vector<int>& vis, vector<int>& pathVis,
             vector<int>& check) {

        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0; // Assume unsafe

        for (int neigh : graph[node]) {

            if (!vis[neigh]) {
                if (dfs(neigh, graph, vis, pathVis, check))
                    return true;
            }
            else if (pathVis[neigh]) {
                return true; // Cycle found
            }
        }

        pathVis[node] = 0;
        check[node] = 1; // Safe
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<int> vis(n, 0);
        vector<int> pathVis(n, 0);
        vector<int> check(n, 0);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, graph, vis, pathVis, check);
            }
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (check[i] == 1)
                ans.push_back(i);
        }

        return ans;
    }
};



