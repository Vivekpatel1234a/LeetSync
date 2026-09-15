class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        for(auto ele:s){
            if(st.empty() || st.top()==ele)st.push(ele);
            else if(tolower(st.top())==ele || toupper(st.top())==ele){
                st.pop();
                continue;
            }
            else{
                st.push(ele);
            }
        }
        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};