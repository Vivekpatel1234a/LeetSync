class Solution {
public:
    int gcd(int a, int b){
        int rem=a%b;
        if(rem==0)return b;
        return gcd(b,rem);
    }
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        vector<int>arr;
        for(int i=0; i<n; i++){
            maxi=max(maxi,nums[i]);
            int val=gcd(maxi,nums[i]);
            arr.push_back(val);
        }
        sort(arr.begin(),arr.end());
        int i=0;
        int j=n-1;
        long long result=0;
        while(i<j){
            result+=gcd(arr[j],arr[i]);
            i++;
            j--;
        }
        return result;
    }
};

/*

(8,5)->r=3
(8,3)->r=2
(8,2)->r=


*/