class Solution {
public:

    void traverse(int node, vector<vector<int>>&adj, vector<int>&visited,int &edgecnt,int &nodecnt){
        visited[node]=1;
        nodecnt++;
        edgecnt+=adj[node].size();
        for(auto ele:adj[node]){
            if(!visited[ele]){
                traverse(ele,adj,visited,edgecnt,nodecnt);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<int>vis(n,0);
        for(int i=0; i<edges.size(); i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt=0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                int edgecnt=0;
                int nodecnt=0;
                traverse(i,adj,vis,edgecnt,nodecnt);
                 if(edgecnt==nodecnt*(nodecnt-1)){
                    cnt++;
                    }
            }
        }
        return cnt;

    }
};