class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
      int n=numCourses;
      vector<vector<int>>adj(n);
      vector<int>indegree(n,0);
        for(auto ele:prerequisites){
            int v=ele[0];
            int u=ele[1];
            adj[u].push_back(v);
            indegree[v]++;

        }
        queue<int>q;
        for(int i=0; i<n; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto ele:adj[node]){
                indegree[ele]--;
                if(indegree[ele]==0)q.push(ele);
            }
        }
        if(ans.size()!=n)return {};
        return ans;
    }
};