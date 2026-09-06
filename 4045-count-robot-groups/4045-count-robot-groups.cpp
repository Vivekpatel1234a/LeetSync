class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
       stack<int>st;
       int n=speed.size();
       int next=speed[0];
       for(int i=0; i<n-1; i++){
        if((position[i+1]-position[i])>distance){
            st.push(next);
        }
        next=speed[i+1];
       }
       st.push(next);
     //  vector<int>relative;
     int top=st.top();
     st.pop();
     int cnt=1;
       while(!st.empty()){
        if(st.top()>top){
            st.pop();
            continue;
        }
        else{
            top=st.top();
            cnt++;
            st.pop();
        }
       }
      /* reverse(relative.begin(),relative.end());
       int cnt=0;
       int next=relative[0];
       for(int i=0; i<relative.size()-1; i++){
        if(next>relative[i+1]){
            next=relative[i+1];
        }
        else{
            cnt++;
        }
       }*/
       return cnt;

    }
};