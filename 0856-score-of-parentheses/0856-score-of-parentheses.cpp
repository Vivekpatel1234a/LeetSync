class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans=0;
        stack<char>st;
        for(auto ele:s){
            st.push(ele);
        }
        stack<int>res;
        while(!st.empty()){
            if(st.top()==')'){
                res.push(0);
            }
            else if(st.top()=='('){
                int ans=0;
                while(res.top()!=0){
                    ans+=res.top();
                    res.pop();
                }
                res.pop();
                if(ans==0)res.push(1);
                else res.push(2*ans);
            }
        st.pop();
        }
        int total=0;
        while(res.size()){
            total+=res.top();
            res.pop();
        }
        return total;
    }
};