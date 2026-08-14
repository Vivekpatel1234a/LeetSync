class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>adj(n,vector<int>(n,1e8));
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u][v]=w;
            adj[v][u]=w;
        }
        for(int t=0; t<n; t++){
            adj[t][t]=0;
        }

        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
                }
            }
        }
        int minicnt=INT_MAX;
        int node=INT_MIN;
        for(int i=0; i<n; i++){
            int cnt=0;
            for(int j=0; j<n; j++){
                //cout<<adj[i][j]<<" ";
                if(adj[i][j]<=distanceThreshold)cnt++;
            }
            if(minicnt>=cnt){
                minicnt=cnt;
                node=max(node,i);
            }
            
        }

        return node;
    }
};