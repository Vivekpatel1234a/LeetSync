class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n=0;
      for(auto it:trips){
        n=max(n,it[2]);
      }
      vector<int>road(n+1);
      for(auto it:trips){
        int passenger=it[0];
        int from=it[1];
        int to=it[2];
        road[from]+=passenger;
        road[to]-=passenger;
      }
      int sum=0;
      for(int i=0; i<=n; i++){
        sum+=road[i];
        road[i]=sum;
        if(road[i]>capacity)return false;
      }
      
      return true;
    }
};