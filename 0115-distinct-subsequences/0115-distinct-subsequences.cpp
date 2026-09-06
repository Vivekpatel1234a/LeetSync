class Solution {
public:
    int dp[1001][1001];
    int solve(string s, string t, int i, int j){
        if(j==t.size())return 1;
        else if(i==s.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        if(s[i]!=t[j]){
            return dp[i][j]=solve(s,t,i+1,j);
        }
        if(s[i]==t[j]){
            return dp[i][j]=solve(s,t,i+1,j+1)+solve(s,t,i+1,j);
        }
        return 0;
    }

    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        int i=0;
        int j=0;
        int ans=solve(s,t,i,j);
        return ans;
    }
};