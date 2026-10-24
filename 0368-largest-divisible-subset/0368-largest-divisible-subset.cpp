class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        vector<int>previdx(n,-1);
        int maxidx=-1;
        int maxcnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j]==0){
                    if(dp[j]>=dp[i]){
                        dp[i]=dp[j]+1;
                        previdx[i]=j;
                        if(maxcnt<dp[i]){
                            maxcnt=dp[i];
                            maxidx=i;
                        }
                    }
                }
            }
        }
        vector<int>result;
        cout<<maxidx;
        if(maxidx==-1)return {nums[0]};
        while(maxidx!=-1){
           // cout<<maxidx<<" ";
            result.push_back(nums[maxidx]);
            maxidx=previdx[maxidx];
        }
        reverse(result.begin(),result.end());
        
        return result;
    }
};



/*
class Solution {
public:
    vector<int>finalans;
    void solve(int i, vector<int> temp,vector<int>& nums){
        if(i==nums.size())return;
        if(temp.size()==0 || nums[i]%temp[temp.size()-1]==0){
            temp.push_back(nums[i]);
            if(temp.size()>finalans.size()){
                finalans=temp;
            }
            solve(i+1,temp,nums);
            temp.pop_back();
        }
        solve(i+1,temp,nums);
        return;
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>temp;
        solve(0,temp,nums);
        return finalans;
    }
};
*/