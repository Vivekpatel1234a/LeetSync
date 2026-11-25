class Solution {
public:
    int countCommas(int n) {
        string x=to_string(n);
        if(x.size()<=3)return 0;
        return n-1000+1;
    }
};