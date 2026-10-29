class Solution {
public:
    int dp[100001][2];
    int solve(int i, int buy, vector<int>& prices){
        if(i==prices.size())return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        int profit=0;
        if(buy){
            int take=solve(i+1,0,prices)-prices[i];
            int nottake=solve(i+1,1,prices);
            profit=max({profit,take,nottake});
        }
        else{
            int sell=prices[i]+solve(i+1,1,prices);
            int notsell=solve(i+1,0,prices);
            profit=max({profit,sell,notsell});
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        int n=prices.size();
        int ans=solve(0,1,prices);
        return ans;
    }
};


//using peak and valley concept
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         int minidx=0;
//         int m=prices[0];
//         int result=0;
//         for(int i=1; i<n; i++){
//             if(prices[i]>m)result+=prices[i]-m;
//             m=prices[i];
//         }
//         return result;
//     }
// };