class Solution {
public:
   vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    stack<int> st;
    vector<int> ans(n);

    // Next Greater Element to the right
    st.push(n-1);
    ans[n-1] = n;

    for(int i = n-2; i >= 0; i--){
        while(!st.empty() && nums[i] >= nums[st.top()]){
            st.pop();
        }
        ans[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    vector<int> res(n - k + 1);

    for(int i = 0; i <= n - k; i++){
        int j = i;   // ✅ reset j for each window
        while(ans[j] < i + k){
            j = ans[j];
        }
        res[i] = nums[j];
    }
    return res;
}

    
};