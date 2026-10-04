class Solution {
public:
    bool checkValidString(string s) {
        int open=0;
        int close=0;
        for(auto ele:s){
            if(ele=='*')open++;
            else if(ele==')'){
                open--;
                if(open<0)return 0;
            }
            else if(ele=='(') open++;
        }
        if(open<0)return 0;
        for(int i=s.size()-1; i>=0; i--){
            char ele=s[i];
            if(ele=='*')close++;
            else if(ele==')')close++;
            else if(ele=='('){
                close--;    
                if(close<0)return 0; 
            }       
        }
        return 1;
    }
};