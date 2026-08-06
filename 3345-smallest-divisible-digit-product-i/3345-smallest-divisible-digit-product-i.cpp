class Solution {
public:
    int smallestNumber(int n, int t) {
        int product=1;
        do{
            int temp=n;
            int prod=1;
            while(temp!=0){
                prod*=(temp%10);
                temp/=10;
            }
            n++;
            product=prod;
        }
        while((product%t)!=0);
        return n-1;
    }
};