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
