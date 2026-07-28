class Solution {
public:
    string smallestPalindrome(string s) {
        map<char,int>mp;
        int n=s.size();
        string ans(n,' ');
        int i=0;
        int j=n-1;
        for(auto ele:s)mp[ele]++;
        for(auto ele:mp){
            char ch=ele.first;
            int cnt=ele.second;
            if(cnt>1){
                while(cnt>1){
                    if(cnt>1){
                        ans[i++]=ch;
                        cnt--;
                        mp[ch]--;
                    }
                    if(cnt){
                        ans[j--]=ch;
                        cnt--;
                        mp[ch]--;
                    }
                }
            }
        }
        for(auto ele:mp){
            if(ele.second==1){
                ans[i++]=ele.first;
            }
        }
        return ans;
    }
};