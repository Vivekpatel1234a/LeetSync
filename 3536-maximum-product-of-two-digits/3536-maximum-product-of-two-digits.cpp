class Solution {
public:
    int maxProduct(int n) {
        string s= to_string(n);
        sort(s.begin(),s.end());
        int p=s.size();
        int l=int(s[p-1]-'0');
        int m=int(s[p-2]-'0');
        return l*m;
    }
};