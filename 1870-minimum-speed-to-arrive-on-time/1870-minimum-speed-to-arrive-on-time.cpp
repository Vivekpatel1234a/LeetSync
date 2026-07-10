class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n=dist.size();
        long long low=1;
        long long high=INT_MAX;
        long long  ans=0;
        while(low<=high){
            long long mid=low+(high-low)/2;
            double timetaken=0;
            for(int i=0; i<n-1; i++){
                timetaken+=ceil(1.0*dist[i]/mid);
            }
            timetaken+=1.0*dist[n-1]/mid;
            if(timetaken<=hour){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans==0?-1:ans;
    }
};