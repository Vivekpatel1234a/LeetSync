class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[n]=1;
        for(int i=n-1; i>=0; i--){
            if(s[i]=='0'){
                dp[i]=0;
            }
            else{
            dp[i]+=dp[i+1];
            if(i+1<n){
                if((s[i]=='1') || (s[i]=='2' && s[i+1]<'7')){
                    dp[i]+=dp[i+2];
                }
            }
        }
        }
        return dp[0];
    }
};


/*
class Solution {
public:
    int dp[101];
    int solve(int i, string s){
        if(i==s.size())return 1;
        if(s[i]=='0')return 0;
        if(dp[i]!=-1)return dp[i];
        int ans=solve(i+1,s);
        if(i+1<s.size()){
        if(s[i]=='1' || (s[i]=='2' && s[i+1]<'7')){
            ans+=solve(i+2,s);
        }
        }
        return dp[i]=ans;
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(0,s);
    }
};
*/