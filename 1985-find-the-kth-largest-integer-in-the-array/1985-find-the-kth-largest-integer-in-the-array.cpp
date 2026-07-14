class Solution {
public:
   static bool cmp(string x, string y){
        if(x.length()<y.length())return true;
        else if(x.length()>y.length())return false;
        if(x.length()==y.length()){
        int n=x.size();
        for(int i=0; i<n; i++){
            if(x[i]==y[i])continue;
            else if(x[i]<y[i])return true;
            else if(x[i]>y[i])return false;
        }
        }
        return false;//t or f
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        vector<int>ans;
        sort(nums.begin(),nums.end(),cmp);
        return nums[nums.size()-k];
    }
};