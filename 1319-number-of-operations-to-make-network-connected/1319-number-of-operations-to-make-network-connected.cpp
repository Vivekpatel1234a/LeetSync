class Solution {
public:

    void solve(int node,vector<int>&visited, vector<vector<int>>&adj){
        visited[node]=1;
        for(auto ele:adj[node]){
            if(!visited[ele]){
                solve(ele,visited,adj);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
       int cablereq=n-1;
       int cablehave=connections.size();
       if(cablereq>cablehave)return -1;
        vector<vector<int>>adj(n);
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>visited(n,0);
        int cnt=0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                solve(i,visited,adj);
                cnt++;
            }
        }

    return cnt-1;//it counts the number of not connected computers and if not connected is cnt then we need cnt-1 cable
    }
};