class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
       int n=nums.size();
       int n1=n/2;
       int n2=n-n1;
       vector<long long>s1(n1);
       vector<long long>s2(n2);
       for(int mask=0; mask<(1<<n1); mask++){
        int sum=0;
        for(int i=0; i<n1; i++){
            if(mask & (1<<i)){
                sum+=nums[i];
            }
        }
       s1.push_back(sum);
       }
        for(int mask=0; mask<(1<<n2); mask++){
        int sum=0;
        for(int i=0; i<n2; i++){
            if(mask & (1<<i)){
                sum+=nums[i+n1];
            }
        }
       s2.push_back(sum);
       }
       long long mini=INT_MAX;
       sort(s2.begin(),s2.end());
       for(auto ele:s1){
        int x=goal-ele;
        int lb=lower_bound(s2.begin(),s2.end(),x)-s2.begin();
        if(lb<s2.size()){
            mini=min(mini,abs(s2[lb]+ele-goal));
        }
        if(lb>0){
            mini=min(mini,abs(s2[lb-1]+ele-goal));
        }
       }


       return mini;
    }
};