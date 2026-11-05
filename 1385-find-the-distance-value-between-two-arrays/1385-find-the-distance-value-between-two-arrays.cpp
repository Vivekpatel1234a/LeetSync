class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
         int ans = 0;
        for(int x : arr1){
            bool t = true;
            for(auto y : arr2){
                int diff = abs(x-y);
                if(diff <= d) t=false;
            }
            if(t) ans++;
        }
        return ans;
    }
};