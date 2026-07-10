class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(m>n/k)return -1;//m*n>k 
        long long low=0;
        long long high=*max_element(bloomDay.begin(),bloomDay.end())*2+1;
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            int flowercount=0;
            int bucketfiled=0;
            for(int i=0; i<n; i++){
                if(bloomDay[i]<=mid){
                    flowercount++;
                }
                if(flowercount==k){
                    bucketfiled++;
                    flowercount=0;
                }
                if(bloomDay[i]>mid){
                    flowercount=0;
                }
            }
            if(bucketfiled>=m){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};