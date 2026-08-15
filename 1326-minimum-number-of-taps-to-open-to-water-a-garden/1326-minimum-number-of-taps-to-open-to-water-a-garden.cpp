class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
       vector<int>garden(n);
       vector<int>area(n+1,0);
       for(int i=n; i>=0; i--){
        int right=min(n,i+ranges[i]);
        int left=max(0,i-ranges[i]);
        area[i]=max(area[i],min(i+ranges[i],n));
        area[left]=max(area[left],min(i+ranges[i],n));
       }
       int cnt=0;
       int nxtidx=0;
       int maxi=0;
       for(int i=0; i<=nxtidx; i++){
        maxi=max(maxi,area[i]);
        if(i==nxtidx){
            //cout<<nxtidx<<" ";
            nxtidx=maxi;
            cnt++;
        }
       }
       if(nxtidx<n)return -1;

       return cnt-1;
    }
};