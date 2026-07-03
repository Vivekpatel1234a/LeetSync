class Solution {
public:


    bool solve(vector<vector<pair<int,long long>>> & adj, long long mid, long long k,vector<long long>& edgeCost){
       
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        int n=adj.size();
        pq.push({0,0});
        edgeCost[0]=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            long long cost=it.first;
            int node=it.second;
            if (cost != edgeCost[node])continue;
           // cout<<" cn-> "<<cost<<" "<<node<<"  ";
            if(cost>k){
               // cout<<"cost>k ";
                continue;
            }
            if(node==n-1)return true;
           // if(cost>mid)return false;
            for(auto ngb:adj[node]){
                int ngbnode=ngb.first;
                long long ngbcost=ngb.second;
               // cout<<ngbcost<<" "<<ngbnode<<" "<<mid<<" ";
                if(ngbcost<mid) continue;
                if(cost+ngbcost<edgeCost[ngbnode]){
                 //   cout<<" done      ";
                    edgeCost[ngbnode]=cost+ngbcost;
                    pq.push({edgeCost[ngbnode],ngbnode});
                }
            }
        }
        return false;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n=online.size();
        vector<vector<pair<int,long long>>> adj(n);
        long long low=LLONG_MAX;
        long long high=LLONG_MIN;
        for(auto& ele:edges){
            int src=ele[0];
            int dest=ele[1];
            long long weight=ele[2];
            low=min(low,weight);
            high=max(high,weight);
            if(!online[src] || !online[dest])continue;
            adj[src].push_back({dest,weight});
        }
        // for(int i=0; i<n; i++){
        //     for(auto ele:adj[i])cout<<ele.first<<" "<<ele.second<<"   ";
        //     cout<<endl;
        // }
        int ans=-1;
        while(low<=high){
            vector<long long>edgeCost(n,LLONG_MAX);
            long long mid=(low+high)/2;
          //  cout<<low<<" "<<high<<" "<<mid<<"   ";
            if(solve(adj,mid,k,edgeCost)){
           //     cout<<"if  ";
                ans=mid;
                low=mid+1;
            }
            else{
            //    cout<<" else  ";
                high=mid-1;
            }
           // cout<<endl;
        }
        
        return ans;
    }
};