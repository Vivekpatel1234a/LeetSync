class Solution {
public:
    int maxProfit(vector<int>& prices) {
     int mini=INT_MAX;
     int maxi=INT_MIN;
     int profit=0;
     int n=prices.size();
     for(int i=0; i<n; i++){
        if(mini>prices[i]){
            mini=prices[i];
            maxi=mini;
        }
        else if(prices[i]>maxi){
            maxi=prices[i];
            profit=max(profit,maxi-mini);
        }
     }
     return profit;  
    }
};