class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
     int n=graph.size();
     vector<int>col(n,-1);
     for(int i=0; i<n; i++){
     if(col[i]==-1){
     queue<int>q;
     q.push(i);
     col[i]=0;
     while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto ele:graph[node]){
            if(col[ele]==-1){
                col[ele]=1-col[node];
                q.push(ele);
            }
            else if(col[ele]==col[node]){
                return 0;
            }
        }
     }  
     }
     }
     return 1; 
    }
};