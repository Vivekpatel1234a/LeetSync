class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int product=1;
        int n2=n;
        while(n2!=0){
            int rem=n2%10;
            sum+=rem;
            product*=rem;
            n2/=10;
        }
        int res=n%(sum+product);
        return res==0;
    }
};