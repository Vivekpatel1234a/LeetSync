class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string sz=to_string(num);
        //cout<<sz;
        bool flag=false;
        int ans=0;
        string result="";
        for(int i=0; i<num; i++){
            int val=9;
            for(val=9; val>=0; val--){
                if(ans+val<=sum){
                    result+=val+'0';
                    ans=ans+val;
                    break;
                }
            }
        }
        if(ans!=sum)return "";
        return result;
    }
};