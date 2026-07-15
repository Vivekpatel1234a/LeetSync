class Solution {
public:
    int gcd(int maxi, int mini){
        int rem=maxi%mini;
        if(rem==0)return mini;
        return gcd(mini,rem);
}
    int gcdOfOddEvenSums(int n) {
        double so=1.0*n/2*(2+(n-1)*2);
        double se=1.0*n/2*(2*2+(n-1)*2);
        int maxi=max(se,so);
        int mini=min(se,so);
        int ans=gcd(maxi,mini);
        return ans;
    }
};