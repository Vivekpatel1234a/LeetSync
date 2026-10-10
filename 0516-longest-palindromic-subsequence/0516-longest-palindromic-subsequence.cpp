class Solution {
public:
    int longestPalindromeSubseq(string s) {
       string str=s;
       reverse(str.begin(),str.end());
       int m=s.size();
       int n=str.size();
       int dp[m+1][n+1];
       memset(dp,0,sizeof(dp));
       for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i==0 || j==0)dp[i][j]=0;
            else if(s[i-1]==str[j-1])dp[i][j]=1+dp[i-1][j-1];
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
       }
       return dp[m][n];        
    }
};

/*
class Solution {
public:
    int dp[1001][1001];
    int LCS(string& a, string& b, int m, int n){
        if(m==0 || n==0)return 0;
        if(dp[m][n]!=-1)return dp[m][n];
        if(a[m-1]==b[n-1])return dp[m][n]=1+LCS(a,b,m-1,n-1);
        else return dp[m][n]=max(LCS(a,b,m,n-1),LCS(a,b,m-1,n));
    }
    int longestPalindromeSubseq(string s) {
        memset(dp,-1,sizeof(dp));
       string str=s;
       reverse(str.begin(),str.end());
       int ans=LCS(s,str,s.size(),str.size());
       return ans;
    }
};
*/