class Solution {
public:
    bool canAliceWin(int n) {
        if(n<10)return 0;
        int rem=n-10;
        int al=1;
        int dec=9;
        while(rem>0){
            if(dec>rem)return al;
            else {
                rem=rem-dec;
                dec--;
                al=1-al;
                }
        }
        return al;
    }
};