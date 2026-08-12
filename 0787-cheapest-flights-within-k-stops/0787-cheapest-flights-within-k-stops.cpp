class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
        }
        queue<pair<int,int>>q;
        q.push({src,0});
        vector<int>cost(n,INT_MAX);
        cost[src]=0;
        int temp=0;
        int ans=INT_MAX;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0; i<sz; i++){
            auto it=q.front();
            q.pop();
            int node=it.first;
            int weight=it.second;
            for(auto ngb:adj[node]){
                int edgecost=ngb.second;
                int ngbnode=ngb.first;
                if(weight+edgecost<cost[ngbnode]){
                    cost[ngbnode]=edgecost+weight;
                    if(temp<=k && ngbnode==dst){
                        ans=min(ans,cost[ngbnode]);
                    }
                    q.push({ngbnode,cost[ngbnode]});
                }
            }
            }
            temp++;
        }
        //for(auto ele:cost)cout<<ele<<" ";
        return ans!=INT_MAX?ans:-1;
    }
};