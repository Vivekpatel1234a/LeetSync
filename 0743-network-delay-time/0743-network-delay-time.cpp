class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        k=k-1;
        vector<vector<pair<int,int>>>adj(n);
        for(auto& it:times){
            int i=it[0]-1;
            int j=it[1]-1;
            int wt=it[2];
            adj[i].push_back({j,wt});
        }
        vector<int>cost(n,INT_MAX);
        queue<int>q;
        q.push(k);
        cost[k]=0;
        int maxi=-1;
        while(!q.empty()){
          int node=q.front();
          int price=cost[node];
          q.pop();
          for(auto& ele:adj[node]){
            int ngb=ele.first;
            int ngbprice=ele.second;
            if(price+ngbprice<cost[ngb]){
                cost[ngb]=price+ngbprice;
                q.push(ngb);
            }
          }

        }
        for(auto& ele:cost){
            maxi=max(maxi,ele);
            if(ele==INT_MAX)return -1;
        }
        return maxi;
    }
};