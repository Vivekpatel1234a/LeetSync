class Solution {
public:
    set<string>st;
    int dp[1000];
    int solve(int idx,string temp, string s){
        if(idx==s.size())return 1;
        if(dp[idx] != -1) return dp[idx];
        for(int i=idx; i<s.size(); i++){
            temp+=s[i];
            if(st.count(temp) && solve(i+1,"",s))return dp[idx]=1;
        }
        return dp[idx]=0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        int i=0;
        memset(dp,-1,sizeof(dp));
        for(auto ele:wordDict)st.insert(ele);
        return solve(i,"",s);
    }
};