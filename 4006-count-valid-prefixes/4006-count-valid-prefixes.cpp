class Solution {
public:
    int countValidPrefixes(string s) {
        int cntzero=0;
        int cntone=0;
        int ans=0;
        for(auto ele:s){
            if(ele=='0')cntzero++;
            else cntone++;
            if(cntzero==cntone || cntzero==cntone-1 || cntone==cntzero-1)ans++;
        }
        return ans;
    }
};