class Solution {
public:
    int smallestNumber(int n, int t) {
        int product=1;
        int ans=0;
        do{
            int temp=n;
            int prod=1;
            while(temp!=0){
                prod*=(temp%10);
                temp/=10;
            }
            ans=n;
            n++;
            product=prod;
        }
        while((product%t)!=0);
        return ans;
    }
};