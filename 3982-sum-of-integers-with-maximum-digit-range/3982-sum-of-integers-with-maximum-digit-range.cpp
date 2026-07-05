class Solution {
public:
    
    int getrange(int n){
        int maxi=INT_MIN;
        int mini=INT_MAX;
        while(n>0){
            maxi=max(maxi,n%10);
            mini=min(mini,n%10);
            n/=10;
        }
         return maxi-mini;
    }

    int maxDigitRange(vector<int>& nums) {
        int topMax=0;
        for(auto ele:nums){
            topMax=max(topMax,getrange(ele));
        }
        int ans=0;
        for(auto ele: nums){
            if(getrange(ele)==topMax)ans+=ele;
        }
        return ans;
    }
};
/* SC=O(n) TC=O(n.d);

class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        vector<vector<int>>store(10);
        int topMax=0;
        for(auto ele:nums){
            int itg=ele;
            int maxi=INT_MIN;
            int mini=INT_MAX;
            while(itg>0){
                int dig=itg%10;
                maxi=max(maxi,dig);
                mini=min(mini,dig);
                itg=itg/10;
            }
            topMax=max(topMax,maxi-mini);
            store[maxi-mini].push_back(ele);
            
        }
        int result=0;
        for(auto ele:store[topMax])result+=ele;
        return result;
    }
};*/