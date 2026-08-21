class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int idx=0;
        bool flag=1;
        string ans="";
        while(flag){
        for(int i=0; i<strs.size(); i++){
            char x;
            if(i==0 && strs[i].length()>0 && idx<strs[i].length()){
                x=strs[0][idx]; 
            }
            else{
                if(x!=strs[i][idx]){
                    flag=false;
                    break;
                }
            }
        }
        if(flag)idx++;
        }
   // cout<<idx;
    if(idx==0)return "";
    string s=strs[0].substr(0,idx);
        return s;
    }
};