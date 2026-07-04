class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
         vector<vector<pair<int, int>>> adj(n+1);
         vector<int>tCost(n+1,INT_MAX);
        int low = INT_MAX;
        int high = INT_MIN;
        for (auto& ele : roads) {
            int src = ele[0];
            int dest = ele[1];
            int weight = ele[2];
            low = min(low, weight);
            high = max(high, weight);
            adj[src].push_back({dest, weight});
            adj[dest].push_back({src, weight});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>>pq;
        pq.push({0,1});
        int mini=INT_MAX;
        while(!pq.empty()){
             auto it = pq.top();
             pq.pop();
             int cost=it.first;
             int node=it.second;
              for (auto ngb : adj[node]) {
                int ngbnode=ngb.first;
                int ngbcost=ngb.second; 
                mini=min(mini,ngbcost);
                if(cost+ngbcost<tCost[ngbnode]){
                    tCost[ngbnode]=cost+ngbcost;
                    pq.push({tCost[ngbnode],ngbnode});
                }

              }

        }
        return mini;
    }
};