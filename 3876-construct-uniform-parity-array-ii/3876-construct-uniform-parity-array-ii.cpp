class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int sm=*min_element(nums1.begin(),nums1.end());
        if(sm%2!=0)return true;
        for(int i=0; i<nums1.size(); i++){
            if(nums1[i]%2!=0)return false;
        }
        return true;
      /* int n=nums1.size();
       vector<int>nums2(n);
       vector<int>nextodd(n);
       vector<int>nexteven(n);
       int nxtodd=INT_MAX;
       int nxteven=INT_MAX;
       for(int i=n-1; i>=0; i--){
        nextodd[i]=nxtodd;
       if(nums1[i]%2!=0)nxtodd=min(nxtodd,nums1[i]);
       }
       for(int i=n-1; i>=0; i--){
        nexteven[i]=nxteven;
       if(nums1[i]%2==0)nxteven=min(nxteven,nums1[i]);
       }

       int pre=INT_MAX;
       int flage=1;
       for(int i=0; i<n; i++){
        if(nums1[i]%2!=0){
            if(i==0 && nums1[i]<nextodd[i]){
                flage=0;
                break;
            }
            else if(i==n-1 && nums1[i]>pre){
                flage=0;
                break;
            }
            else if(nums1[i]<pre && nums1[i]<nextodd[i]){
                flage=0;
                break;
            }
         pre=min(pre,nums1[i]);
        }
       }
       //check for odd
       pre=INT_MAX;
       int flago=1;
       for(int i=0; i<n; i++){
        if(nums1[i]%2==0){
            if(i==0 && nums1[i]<nextodd[i]){
                flago=0;
                break;
            }
            else if(i==n-1 && pre>nums1[i]){
                flago=0;
                break;
            }
            else if(nums1[i]<pre && nums1[i]<nextodd[i]){
                flago=0;
                break;
            }
        }
        else pre=min(pre,nums1[i]);
       }
       return flage||flago;*/
    }
};