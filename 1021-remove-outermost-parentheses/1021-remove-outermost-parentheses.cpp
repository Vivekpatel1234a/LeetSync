class Solution {
public:
    string removeOuterParentheses(string s) {
        int op=0;
        int cl=0;
        string ans="";
        for(auto ele:s){
            if(ele=='('){
               if(op==0)op++;
               else{
                op++;
                ans+=ele;
               }
            }
            else{
                if(op==1)op--;
                else{
                    op--;
                    ans+=ele;
                }
            }
        }
        return ans;
    }
};