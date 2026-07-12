class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
       map<int,vector<int>>mp;
       for(int i=0; i<n; i++)mp[arr[i]].push_back(i);
       int order=0;
       for(auto it:mp){
        order++;
        for(auto ele:it.second)arr[ele]=order;
       }
        return arr;
    }
};