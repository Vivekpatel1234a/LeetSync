class Solution {
public:
    string digitSum(string s, int k) {
        string x="";
        int ans=0;
        if(s.size()<=k)return s;
        while(s.size()>k){
            x="";
            bool flag=false;
            ans=0;
            for(int i=0; i<s.size(); i++){
                ans+=s[i]-'0';
                flag=false;
                if((i+1)%k==0){
                    x+=to_string(ans);
                    flag=true;
                    ans=0;
                }
            }
            if(flag==false)x+=to_string(ans);
            s=x;
            cout<<x<<" ";
        }
        return x;
    }
};