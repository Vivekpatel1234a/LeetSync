class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int>mp;
        int cnt=0;
        for(auto ele:s)mp[ele]++;
        bool odd=0;
        for(auto it:mp){
            if(it.second%2==0)cnt+=it.second;
            else{
                odd=true;
                cnt+=it.second-1;
            }
        }
        if(odd)cnt+=1;
        return cnt;
    }
};