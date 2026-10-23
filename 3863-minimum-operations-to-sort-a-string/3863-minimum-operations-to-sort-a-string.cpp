class Solution {
public:
    int minOperations(string s) {
       int n=s.size();
       string x=s;
       sort(x.begin(),x.end());
       if(x==s)return 0;
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