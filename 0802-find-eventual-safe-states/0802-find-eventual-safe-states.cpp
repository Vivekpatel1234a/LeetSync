class Solution {
public:

    int cycle(int node, vector<int>&vis, vector<vector<int>>& adj){
      vis[node]=1;
      for(auto& ngb:adj[node]){
        if(vis[ngb]==1)return 1;
        else if(vis[ngb]==2)continue;
        if(cycle(ngb,vis,adj))return 1;
      }
      vis[node]=2;
      return 0;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>ans;
        int n=graph.size();
        vector<int>visited(n,0);
        for(int i=0; i<n; i++){
            if(cycle(i,visited,graph)==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};