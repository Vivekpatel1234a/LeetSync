class Solution {
public:
    string smallestSubsequence(string s) {
       unordered_map<char,int>visited;
        for(auto ele:s){
            visited[ele]=0;
            
        }
        stack<char>stk;
        unordered_map<char,int>index;
        for(int i=0; i<s.size(); i++){
            index[s[i]]=i;
        }
        for(int i=0; i<s.size(); i++){
            if(stk.empty()){
                stk.push(s[i]);
                visited[s[i]]=1;
            }
            else{
                if(!visited[s[i]]){
                    while(!stk.empty() && stk.top()>s[i] && index[stk.top()]>i){
                        visited[stk.top()]=0;
                        stk.pop();
                    }
                    stk.push(s[i]);
                    visited[s[i]]=1;
                }
            }
        }
        string ans="";
        while(!stk.empty()){
            ans+=stk.top();
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;  
    }
};