class Solution {
public:
    int minOperations(string s) {
       int n=s.size();
       bool flag=false;
       for(int i=1; i<n; i++){
        if(s[i]<s[i-1]){
            flag=true;
            break;
        }
       }
       if(flag==false)return 0;
       else if(s.size()==2)return -1;
       int minidx=0;
       int maxidx=0;
       for(int i=1; i<n; i++){
        if(s[i]>=s[maxidx]){
            maxidx=i;
        }
        else if(s[i]<s[minidx]){
            minidx=i;
        }
       }
       if(maxidx==0 && minidx==n-1)return 3;
       else if(maxidx==n-1 || minidx==0)return 1;
       return 2;
    }
};