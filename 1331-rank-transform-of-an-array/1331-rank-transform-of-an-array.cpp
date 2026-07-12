class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans=arr;
        sort(ans.begin(),ans.end());
       unordered_map<int,int>mp;
       int order=1;
       for(int i=0; i<n; i++){
        if(!mp.count(ans[i])){
            mp[ans[i]]=order;
            order++;
        }
       }
       
       for(int i=0; i<n; i++){
        arr[i]=mp[arr[i]];
       }
        return arr;
    }
};



//not optimal but good 
/*class Solution {
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
};*/