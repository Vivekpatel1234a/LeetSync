class Solution {
public:
    int maximumLengthSubstring(string s) {
    int n=s.size();
    int k=2;
        unordered_map<int,int>mp;
        int j=0;
        int maxi=0;
        for(int i=0; i<n; i++){
            while(j<n && mp[s[j]-'0']<k){
                mp[s[j]-'0']++;
                j++;
            }
            maxi=max(maxi,j-i);
            mp[s[i]-'0']--;
        }
        return maxi;    
    }
};