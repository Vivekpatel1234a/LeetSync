//optimise it
class Solution {
public:
    int scoreOfParentheses(string s) {
        /*int ans=0;
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
                while(res.size() && res.top()!=0){
                    ans+=res.top();
                    res.pop();
                }
               if(res.size()) res.pop();
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
        return total;*/
        int n=s.size();
        stack<int>st;
        for(auto ele:s){
            if(ele=='(')st.push(-1);
            else if(ele==')'){
                if(st.top()==-1){
                    st.pop();
                    st.push(1);
                }
                else{
                    int temp=0;
                    while(!st.empty() && st.top()!=-1){
                        temp+=st.top();
                        st.pop();
                    }
                    st.pop();
                    st.push(temp*2);
                }
            }
        }
        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
return ans;
    }
};