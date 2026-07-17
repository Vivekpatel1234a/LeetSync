class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        int n2=nums2.size();
        int n=nums1.size();
        stack<int>st;
        int j=n2-1;
        while(j>=0){
            while(!st.empty() && st.top()<nums2[j]){
                st.pop();
            }
            if(st.empty()){
                mp[nums2[j]]=-1;
                st.push(nums2[j]);
                
            }
            else{
                mp[nums2[j]]=st.top();
                st.push(nums2[j]);
            }
            j--;
        }
        vector<int>ans(n);
        for(int i=0; i<n; i++){
            ans[i]=mp[nums1[i]];
        }

        return ans;
    }
};