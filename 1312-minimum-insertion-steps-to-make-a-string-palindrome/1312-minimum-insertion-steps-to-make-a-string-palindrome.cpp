class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();;
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        for(int i=0; i<n; i++)dp[i][i]=0;//coz 1 length hai to we dont need to insert something
        for(int l=2; l<=n; l++){
            for(int i=0; l+i-1<n; i++){
                int j=l+i-1;
                if(s[i]==s[j]){
                    dp[i][j]=dp[i+1][j-1];
                }
                else{
                    dp[i][j]=1+min(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};


//////rec+memo
/*
class Solution {
public:
    int dp[500][500];
    int solve(int i,int j, string& s){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==s[j]){
            return dp[i][j]=solve(i+1,j-1,s);
        }
        else{
            return dp[i][j]=1+min(solve(i+1,j,s),solve(i,j-1,s));
        }
    }
    int minInsertions(string s) {
        memset(dp,-1,sizeof(dp));
       int n=s.size();
       int ans=solve(0,n-1,s);
       return ans; 
    }
};
*/

///ADV
/*
class Solution {
public:
    int minInsertions(string s) {
       string s2=s;
       reverse(s2.begin(),s2.end());
       int m=s.size();
       int n=s2.size();
       int dp[m+1][n+1];
       for(int i=0; i<=m ; i++){
        for(int j=0; j<=n; j++){
            if(i==0 || j==0)dp[i][j]=0;
            else if(s[i-1]==s2[j-1])dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
       }
       return n-dp[m][n]; 
    }
};
*/