class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>lh(n);
        vector<int>rh(n);
        lh[0]=0;
        rh[n-1]=0;
        int maxi=0;
        for(int i=0; i<n; i++){
            lh[i]=maxi;
            if(height[i]>maxi){
                maxi=height[i];
            }
            
        }
        maxi=0;
        for(int i=n-1; i>=0; i--){
            rh[i]=maxi;
            if(height[i]>maxi){
                maxi=height[i];
            }
        }
        int result=0;
        for(int i=0; i<n; i++){
            int temp=min(lh[i],rh[i])-height[i];
            if(temp>=0)result+=temp;
        }
        return result;
    }
};