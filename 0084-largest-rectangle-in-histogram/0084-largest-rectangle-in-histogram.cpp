class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        vector<int> prev(n);
        vector<int> next(n);
        stack<int> st;
        // Previous Smaller Element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                prev[i] = -1;
            }
            else {
                prev[i] = st.top();
            }
            st.push(i);
        }
        // Clear stack
        while (!st.empty()) {
            st.pop();
        }
        // Next Smaller Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                next[i] = n;
            }
            else {
                next[i] = st.top();
            }
            st.push(i);
        }
        // Calculate maximum area
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            int width = next[i] - prev[i] - 1;
            maxi=max(maxi,width * arr[i]);
            
        }
        return maxi;
    }
}; 

/*
class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // code here
        int n=arr.size();
        int i=0;
        int j=n-1;
        int maxi=0;
        stack<int>st;
        vector<int>prev(n);
        vector<int>next(n);
        for(int i=0; i<n; i++){
            if(st.empty()){
                prev[i]=0;
            }
            else{
                while(!st.empty() &&  arr[st.top()]>=arr[i]){
                    st.pop();
                }
                if(st.empty())prev[i]=0;
                else prev[i]=st.top()+1;
            }
            st.push(i);
        }
     while (!st.empty()) st.pop();
        for(int i=n-1; i>=0; i--){
            if(st.empty())next[i]=n;
            else{
                while(!st.empty() && arr[st.top()]>=arr[i]){
                    st.pop();
                }
                if(st.empty())next[i]=n;
                else next[i]=st.top();
            }
            st.push(i);
        }
        for(int i=0; i<n; i++){
            maxi=max(maxi,(next[i]-prev[i])*arr[i]);
        }
        return maxi;
    }
};
*/