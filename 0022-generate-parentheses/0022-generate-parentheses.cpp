class Solution {
public:

    void solve(int open, int close, string &s, vector<string>&ans,int n){
        if(open==n && close==n){
            ans.push_back(s);
            return;
        }
        else if(open==close){
            s.push_back('(');
            solve(open+1,close,s,ans,n);
            s.pop_back();
        }
        else if(open==n){
          s.push_back(')');
            solve(open,close+1,s,ans,n);
            s.pop_back();

        }
        else{
          s.push_back('(');
           solve(open+1,close,s,ans,n);
            s.pop_back();
         s.push_back(')');
           solve(open,close+1,s,ans,n);
             s.pop_back();
        }

    }

    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string str="";
        solve(0,0,str,ans,n);
        return ans;
    }
};