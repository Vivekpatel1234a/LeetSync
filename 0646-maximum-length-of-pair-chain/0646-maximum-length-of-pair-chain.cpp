class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<int>dp(n,1);
        int maxi=1;
        for(int i=0; i<n; i++){
            int second=pairs[i][0];
            for(int j=0; j<i; j++){
              int first=pairs[j][1];
              if(first<second){
                dp[i]=max(dp[i],1+dp[j]);
                maxi=max(maxi,dp[i]);
              }  
            }
        }
        return maxi;
    }
};