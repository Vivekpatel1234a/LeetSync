class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
         int  n=isConnected.size();
        //instead of 1 2 3 we used 0 1 2 so that it makes the complex nodes into easy ones
        vector<vector<int>>adj(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                }
            }
        }
       
        int cnt=0;
        vector<int> visited(n);
        for(int i=0; i<n; i++){
            if(!visited[i]){
                cnt++;
                 queue<int>q;
                 q.push(i);
                  visited[i]=1;
                 while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(auto ele:adj[node]){
                        if(!visited[ele]){
                            visited[ele]=1;
                            q.push(ele);
                        }
                    }
                 }
            }
        }
        return cnt;
        }
};
/*class Solution {
public:

    void solve(int node,vector<int>& visited, vector<vector<int>>& adj){
        visited[node]=1;
        for(auto ele:adj[node]){
            if(!visited[ele]){
                solve(ele,visited,adj);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int  n=isConnected.size();
        //instead of 1 2 3 we used 0 1 2 so that it makes the complex nodes into easy ones
        vector<vector<int>>adj(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                }
            }
        }
            int cnt=0;
            vector<int>visited(n);
            for(int i=0; i<n; i++){
                if(!visited[i]){
                    solve(i,visited,adj);
                    cnt++;
                }
            }

        
        return cnt;
    }
};*/