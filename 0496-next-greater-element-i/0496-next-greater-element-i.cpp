class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        int n2=nums2.size();
        int n=nums1.size();
        for(int i=0; i<n2; i++){
            mp[nums2[i]]=i;
        }
        vector<int>ng(n2);
        stack<int>st;
        int j=n2-1;
        while(j>=0){
            while(!st.empty() && st.top()<nums2[j]){
                st.pop();
            }
            if(st.empty()){
                ng[j]=-1;
                st.push(nums2[j]);
            }
            else{
                ng[j]=st.top();
                st.push(nums2[j]);
            }
            j--;
        }
        vector<int>ans(n);
        for(int i=0; i<n; i++){
            ans[i]=ng[mp[nums1[i]]];
        }

        return ans;
    }
};