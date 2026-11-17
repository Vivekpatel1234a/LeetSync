class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> arr(n);
        int maxi = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(matrix[i][j]=='0')arr[j]=0;
                arr[j]+=matrix[i][j]-'0';
            }
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
                    } else {
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
                    } else {
                        next[i] = st.top();
                    }
                    st.push(i);
                }
                int scopemaxi = 0;
                for (int i = 0; i < n; i++) {
                    int width = next[i] - prev[i] - 1;
                    scopemaxi = max(scopemaxi, width * arr[i]);
                }
                maxi=max(maxi,scopemaxi);
            }
        return maxi;
    }
};