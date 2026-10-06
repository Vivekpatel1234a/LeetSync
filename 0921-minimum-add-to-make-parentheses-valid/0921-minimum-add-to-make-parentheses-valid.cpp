class Solution {
public:
    int minAddToMakeValid(string s) {
    int op=0;
    int cnt=0;
    for(auto ele:s){
        if(ele=='(')op++;
        else if(ele==')'){
            if(op)op--;
            else cnt++;
        }
    }
    return cnt+op;
    }
};