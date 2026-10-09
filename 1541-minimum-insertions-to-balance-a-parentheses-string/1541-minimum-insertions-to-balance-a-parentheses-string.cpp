class Solution {
public:
    int minInsertions(string s) {
       int n=s.size();
       string str="";
       for(int i=0; i<n; i++){
        if(s[i]==')'){
            if(i+1<n && s[i+1]==')'){
                str+='*';
                i++;
            }
            else str+=s[i];
        }
        else{
            str+=s[i];
        }
       }
       int op=0;
       int cl=0;
       n=str.size();
       int cnt=0;
       for(int i=0; i<n; i++){
        if(str[i]=='(')op++;
        else{
            if(str[i]=='*'){
                if(op>0)op--;
                else cnt++;
            }
            else{
                if(op>0){
                    cnt++;
                    op--;
                }
                else{
                    cnt+=2;
                }
            }
        }
       }
       if(op){
        cnt+=op*2;
       }
       if(cl){
        cnt+=cl;
       }
        return cnt;
    }
};